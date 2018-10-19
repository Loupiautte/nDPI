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

static inline bool match_rtmfp(lpi_data_t *data, lpi_module_t *mod UNUSED) {

	/* RTMFP is Adobe's proprietary P2P streaming protocol. There are two
	 * stages - communicating with the Stratus servers && then talking
	 * to the peers themselves */

	/* Basically we're matching pairs of packet sizes here - not very
	 * reliable at all. Could be lots of false positives! */

	/* Hitting the Stratus servers */
	if (data->payload_len[0] == 100 && data->payload_len[1] == 180)
		return true;
	if (data->payload_len[1] == 100 && data->payload_len[0] == 180)
		return true;

	/* P2P */
	if (data->payload_len[0] == 228 && data->payload_len[1] == 68)
		return true;
	if (data->payload_len[1] == 228 && data->payload_len[0] == 68)
		return true;
	if (data->payload_len[0] == 68 && data->payload_len[1] == 68)
		return true;
	if (data->payload_len[1] == 68 && data->payload_len[0] == 68)
		return true;
	

	return false;
}

static lpi_module_t lpi_rtmfp = {
	LPI_PROTO_UDP_RTMFP,
	LPI_CATEGORY_STREAMING,
	"RTMFP",
	12,
	match_rtmfp
};

void register_rtmfp(LPIModuleMap *mod_map) {
	register_protocol(&lpi_rtmfp, mod_map);
}

