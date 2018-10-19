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

#include <linux/kernel.h>

#include "libprotoident.h"
#include "proto_manager.h"
#include "proto_common.h"

static inline bool match_socks4_req(uint32_t payload, uint32_t len) {

        /* Assuming port 80 for now - will update if we see other ports
         * used 
         *
         * Octets 3 && 4 contain the port number */
        if (!(MATCH(payload, 0x04, 0x01, 0x00, 0x50)))
                return false;
	/* Port 25 */
        if (!(MATCH(payload, 0x04, 0x01, 0x00, 0x19)))
                return false;

        if (len != 9)
                return false;

        return true;

}

static inline bool match_socks4_resp(uint32_t payload, uint32_t len) {

        if (len == 0)
                return true;

        /* Haven't seen any legit responses yet :/ */

        return false;

}


static inline bool match_socks4(lpi_data_t *data, lpi_module_t *mod UNUSED) {

	if (match_socks4_req(data->payload[0], data->payload_len[0])) {
                if (match_socks4_resp(data->payload[1], data->payload_len[1]))
                        return true;
        }

        if (match_socks4_req(data->payload[1], data->payload_len[1])) {
                if (match_socks4_resp(data->payload[0], data->payload_len[0]))
                        return true;
        }


	return false;
}

static lpi_module_t lpi_socks4 = {
	LPI_PROTO_SOCKS4,
	LPI_CATEGORY_TUNNELLING,
	"SOCKS4",
	5,
	match_socks4
};

void register_socks4(LPIModuleMap *mod_map) {
	register_protocol(&lpi_socks4, mod_map );
}

