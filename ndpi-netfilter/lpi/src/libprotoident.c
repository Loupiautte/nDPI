/*
 *
 * Copyright (c) 2011-2016 The University of Waikato, Hamilton, New Zealand.
 * All rights reserved.
 *
 * This file is part of libprotoident.
 *
 * This code has been developed by the University of Waikato WAND
 * research group. For further information please see http://www.wand.net.nz/
 *
 * libprotoident is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libprotoident is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#define __STDC_FORMAT_MACROS
#define __STDC_LIMIT_MACROS

//#include <stdio.h>
//#include <assert.h>
//#include <inttypes.h>
//#include <sys/types.h>
//#include <stdint.h>
//#include <stdlib.h>
//#include <signal.h>
//

#include "libprotoident.h"
#include "proto_manager.h"
#include <net/net_namespace.h>
#include <linux/list.h>
#include <linux/uaccess.h>


static struct proc_dir_entry *pde_lpi;
static char dir_name[]="xt_lpi";
static char proto_lpi_name[]="proto_lpi";
static bool init_called = false;
LPIModuleMap TCP_protocols;
LPIModuleMap UDP_protocols;

static const struct file_operations lpi_proc_fops = {
        .owner = THIS_MODULE,
        .read    = lpi_proc_read,
        .write = lpi_proc_write,
};

//lpi_module_t *lpi_icmp = NULL;
//lpi_module_t *lpi_unsupported = NULL;
//lpi_module_t *lpi_unknown_tcp = NULL;
//lpi_module_t *lpi_unknown_udp = NULL;

//static LPINameMap lpi_names;

//static int seq_cmp(uint32_t seq_a, uint32_t seq_b) {
//
//    if (seq_a == seq_b) return 0;
//
//
//    if (seq_a > seq_b)
//        return (int) (seq_a - seq_b);
//    else
//        /* WRAPPING */
//        return (int) (UINT32_MAX - ((seq_b - seq_a) - 1));

//}

int lpi_init_library() {

    if (init_called) {
        printk(KERN_WARNING
        "WARNING: lpi_init_library has already been called\n");
        return 0;
    }

    INIT_LIST_HEAD(&TCP_protocols.list);
    INIT_LIST_HEAD(&UDP_protocols.list);
    if (register_tcp_protocols(&TCP_protocols) == -1) {
        return -1;
    }

    if (register_udp_protocols(&UDP_protocols) == -1) {
        return -1;
    }

    /* Create proc files */

    if(lpi_create_files()){
        printk(KERN_ERR
        "LPI : ERROR : can't created files");
        return -1;
    }


//    init_other_protocols(&lpi_names);
//
//    register_names(&TCP_protocols, &lpi_names);
//    register_names(&UDP_protocols, &lpi_names);
//
    init_called = true;

    if (list_empty(&TCP_protocols.list) && list_empty(&UDP_protocols.list)) {
        printk(KERN_WARNING
        "LPI : WARNING: No protocol modules loaded");
        return -1;
    }

    return 0;

}

void lpi_free_library() {

    printk(KERN_NOTICE
    "LPI : Free library");
    free_protocols(&TCP_protocols);
    free_protocols(&UDP_protocols);
    lpi_delete_files();


//    if (lpi_icmp != NULL) {
//        delete lpi_icmp;
//        lpi_icmp = NULL;
//    }
//
//    if (lpi_unsupported != NULL) {
//        delete lpi_unsupported;
//        lpi_unsupported = NULL;
//    }
//
//    if (lpi_unknown_tcp != NULL) {
//        delete lpi_unknown_tcp;
//        lpi_unknown_tcp = NULL;
//    }
//
//    if (lpi_unknown_udp != NULL) {
//        delete lpi_unknown_udp;
//        lpi_unknown_udp = NULL;
//    }
//
    init_called = false;
}

void lpi_process_packet(u8 payload_ori[4], u8 payload_reply[4], unsigned int data_len[2], unsigned short lpi_original_port_dst, unsigned short lpi_original_port_src, char is_TCP) {
    lpi_data_t data;
    lpi_module_t *proto = NULL;
    LPIModuleMap m_it;

    lpi_init_data(&data);

    printk(KERN_NOTICE "LPI : Payload original :  %02x %02x %02x %02x", payload_ori[0], payload_ori[1], payload_ori[2], payload_ori[3]);
    printk(KERN_NOTICE "LPI : Payload reply :  %02x %02x %02x %02x", payload_reply[0], payload_reply[1], payload_reply[2], payload_reply[3]);
    printk(KERN_NOTICE "LPI : Data len original : %d", data_len[0]);
    printk(KERN_NOTICE "LPI : Data len reply : %d", data_len[1]);
//    printk(KERN_NOTICE "LPI : Port source : %hu", lpi_original_port_src);
//    printk(KERN_NOTICE "LPI : Port dest : %hu", lpi_original_port_dst);

    data.payload[0] = ((payload_ori[0] & 0xff) << 24) | ((payload_ori[1] & 0xff) << 16) | ((payload_ori[2] & 0xff) << 8) | (payload_ori[3] & 0xff);
    data.payload[1] =  ((payload_reply[0] & 0xff) << 24) | ((payload_reply[1] & 0xff) << 16) | ((payload_reply[2] & 0xff) << 8) | (payload_reply[3] & 0xff);
    data.payload_len[0] = data_len[0];
    data.payload_len[1] = data_len[1];
    data.client_port = lpi_original_port_src;
    data.server_port = lpi_original_port_dst;


    proto = guess_protocol(&data, is_TCP);
    if(is_TCP){
        printk(KERN_NOTICE "LPI : Found TCP : %s", proto->name);
    } else {
        printk(KERN_NOTICE "LPI : Found UDP : %s", proto->name);
    }
    printk(KERN_NOTICE " ");
}

void lpi_init_data(lpi_data_t *data) {

    data->payload[0] = 0;
    data->payload[1] = 0;
    data->seen_syn[0] = false;
    data->seen_syn[1] = false;
    data->seqno[0] = 0;
    data->seqno[1] = 0;
    data->observed[0] = 0;
    data->observed[1] = 0;
    data->server_port = 0;
    data->client_port = 0;
    data->trans_proto = 0;
    data->payload_len[0] = 0;
    data->payload_len[1] = 0;
    data->ips[0] = 0;
    data->ips[1] = 0;

}



static lpi_module_t *test_protocol_list(LPIModuleList *ml, lpi_data_t *data) {

    LPIModuleList *l_it;

    list_for_each_entry(l_it, &ml->list, list)
    {
        //access the member from l_it
        lpi_module_t *module = &(l_it->lpi_module1);
        if (module->lpi_callback(data, module)) {
            return module;
        }
    }

    return NULL;
}

lpi_module_t *guess_protocol(lpi_data_t *data, char is_TCP) {
    lpi_module_t *proto = NULL;

    LPIModuleMap *m_it;
    if(is_TCP){
        list_for_each_entry(m_it, &TCP_protocols.list, list)
        {
            LPIModuleList *ml = m_it->lpiModuleList;

            proto = test_protocol_list(ml, data);

            if (proto != NULL){
                return proto;
            }
        }
    }
    else{
        list_for_each_entry(m_it, &UDP_protocols.list, list)
        {
            LPIModuleList *ml = m_it->lpiModuleList;

            proto = test_protocol_list(ml, data);

            if (proto != NULL){
                return proto;
            }
        }

        return proto;
    }
}

lpi_category_t lpi_categorise(lpi_module_t *module) {

    if (module == NULL)
        return LPI_CATEGORY_NO_CATEGORY;

    return module->category;

}

const char *lpi_print_category(lpi_category_t category) {

    switch (category) {
        case LPI_CATEGORY_WEB:
            return "Web";
        case LPI_CATEGORY_MAIL:
            return "Mail";
        case LPI_CATEGORY_CHAT:
            return "Chat";
        case LPI_CATEGORY_P2P:
            return "P2P";
        case LPI_CATEGORY_P2P_STRUCTURE:
            return "P2P_Structure";
        case LPI_CATEGORY_KEY_EXCHANGE:
            return "Key_Exchange";
        case LPI_CATEGORY_ECOMMERCE:
            return "ECommerce";
        case LPI_CATEGORY_GAMING:
            return "Gaming";
        case LPI_CATEGORY_ENCRYPT:
            return "Encryption";
        case LPI_CATEGORY_MONITORING:
            return "Measurement";
        case LPI_CATEGORY_NEWS:
            return "News";
        case LPI_CATEGORY_MALWARE:
            return "Malware";
        case LPI_CATEGORY_SECURITY:
            return "Security";
        case LPI_CATEGORY_ANTISPAM:
            return "Antispam";
        case LPI_CATEGORY_VOIP:
            return "VOIP";
        case LPI_CATEGORY_TUNNELLING:
            return "Tunnelling";
        case LPI_CATEGORY_NAT:
            return "NAT_Traversal";
        case LPI_CATEGORY_STREAMING:
            return "Streaming";
        case LPI_CATEGORY_SERVICES:
            return "Services";
        case LPI_CATEGORY_DATABASES:
            return "Databases";
        case LPI_CATEGORY_FILES:
            return "File_Transfer";
        case LPI_CATEGORY_REMOTE:
            return "Remote_Access";
        case LPI_CATEGORY_TELCO:
            return "Telco_Services";
        case LPI_CATEGORY_P2PTV:
            return "P2PTV";
        case LPI_CATEGORY_RCS:
            return "Revision_Control";
        case LPI_CATEGORY_LOGGING:
            return "Logging";
        case LPI_CATEGORY_PRINTING:
            return "Printing";
        case LPI_CATEGORY_TRANSLATION:
            return "Translation";
        case LPI_CATEGORY_CDN:
            return "CDN";
        case LPI_CATEGORY_CLOUD:
            return "Cloud";
        case LPI_CATEGORY_NOTIFICATION:
            return "Notification";
        case LPI_CATEGORY_SERIALISATION:
            return "Serialisation";
        case LPI_CATEGORY_BROADCAST:
            return "Broadcast";
        case LPI_CATEGORY_LOCATION:
            return "Location";
        case LPI_CATEGORY_CACHING:
            return "Caching";
        case LPI_CATEGORY_ICS:
            return "ICS";
        case LPI_CATEGORY_MOBILE_APP:
            return "Mobile App";
        case LPI_CATEGORY_IPCAMERAS:
            return "IP Cameras";
        case LPI_CATEGORY_ICMP:
            return "ICMP";
        case LPI_CATEGORY_MIXED:
            return "Mixed";
        case LPI_CATEGORY_NOPAYLOAD:
            return "No_Payload";
        case LPI_CATEGORY_UNKNOWN:
            return "Unknown";
        case LPI_CATEGORY_UNSUPPORTED:
            return "Unsupported";
        case LPI_CATEGORY_NO_CATEGORY:
            return "Uncategorised";
        case LPI_CATEGORY_LAST:
            return "Invalid_Category";
    }

    return "Invalid_Category";

}



ssize_t lpi_proc_write(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos){
    printk( KERN_DEBUG "write handler\n");
    return -1;
}

ssize_t lpi_proc_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos){
    char buf[128] = {0};
    int index = 0;
    int len = 0;

    LPIModuleMap *node;
    LPIModuleList *node_list;

    list_for_each_entry(node, &(TCP_protocols.list), list){
        list_for_each_entry(node_list, &((node->lpiModuleList)->list), list){
            if(*ppos == index){
                len = strlcpy(buf, (node_list->lpi_module1).name, sizeof(buf));
                if(copy_to_user(ubuf,buf,strlen(buf)+1))
                    return -EFAULT;
                (*ppos)++;
                return strlen(buf) + 1;
            }
            index++;
        }
    }
    return 0;
}

int lpi_create_files(){
    struct proc_dir_entry *pde;
    pde =
        proc_mkdir(dir_name, init_net.proc_net );

    if (pde == NULL) {
        printk(KERN_ERR
        "LPI: cant create net/%s", dir_name);
        return -ENOMEM;
    }

    pde_lpi=proc_create(proto_lpi_name , 0, pde, &lpi_proc_fops);

    if (pde_lpi == NULL) {
        printk(KERN_ERR
        "LPI: cant create net/%s", proto_lpi_name);
        return -ENOMEM;
    }

    return 0;
}

void lpi_delete_files(){
    proc_remove(pde_lpi);
    remove_proc_entry(dir_name, init_net.proc_net);
}
