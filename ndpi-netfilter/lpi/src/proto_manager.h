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


#ifndef PROTO_MANAGER_H_
#define PROTO_MANAGER_H_

#include <linux/kernel.h>
#include <linux/list.h>
#include "libprotoident.h"


typedef struct lpimodulelist
{
    lpi_module_t lpi_module1;
    struct list_head list;
} LPIModuleList;

typedef struct lpimodulemap
{
    uint8_t priority;
    LPIModuleList *lpiModuleList;
    struct list_head list;
} LPIModuleMap;

typedef struct lpinamemap
{
    lpi_protocol_t lpi_protocol;
    const char *string;
    struct list_head list;
} LPINameMap;

void register_protocol(lpi_module_t *mod, LPIModuleMap *mod_map);
int register_tcp_protocols(LPIModuleMap *mod_map);
int register_udp_protocols(LPIModuleMap *mod_map);
void register_names(LPIModuleMap *mod_map, LPINameMap *name_map);
void init_other_protocols(LPINameMap *name_map);
void free_protocols(LPIModuleMap *mod_map);

#endif
