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

static bool match_akamai_out(uint32_t payload, uint32_t len) {

	if (len < 200)
		return false;

	if (MATCH(payload, 0x02, 0x24, ANY, ANY))
		return true;
	return false;

}

static inline bool match_akamai_transfer(lpi_data_t *data, lpi_module_t *mod UNUSED) {

	/* This protocol is used by Akamai boxes to transfer large quantities
	 * of data back to the main Akamai network. This involves a one-way
	 * UDP flow */


	/* Restrict based on port number, because this rule is a bit weak */
	if (data->server_port != 1485 && data->client_port != 1485)
		return false;

	if (match_akamai_out(data->payload[0], data->payload_len[0])) {
		if (data->payload_len[1] == 0)
			return true;
	}
	
	if (match_akamai_out(data->payload[1], data->payload_len[1])) {
		if (data->payload_len[0] == 0)
			return true;
	}

	return false;
}

static lpi_module_t lpi_akamai_transfer = {
	LPI_PROTO_UDP_AKAMAI_TRANSFER,
	LPI_CATEGORY_CDN,
	"AkamaiTransfer",
	15,
	match_akamai_transfer
};

void register_akamai_transfer(LPIModuleMap *mod_map) {
	register_protocol(&lpi_akamai_transfer, mod_map);
}

