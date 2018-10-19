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

static inline bool match_irc(lpi_data_t *data, lpi_module_t *mod UNUSED) {

	if (match_str_either(data, "PASS"))
		return true;
	if (match_str_either(data, "NICK"))
		return true;
	if (MATCHSTR(data->payload[0], "\x0aNIC"))
		return true;
	if (MATCHSTR(data->payload[1], "\x0aNIC"))
		return true;
	if (match_str_both(data, ":irc", "USER"))
		return true;
	if (match_str_both(data, ":loc", "MODE"))
		return true;


	/* Trying to match on broken IRC implementations :) */
	if (data->server_port == 6667 || data->client_port == 6667) {
		if (match_str_either(data, "ERRO"))
			return true;
	}

	return false;
}

static lpi_module_t lpi_irc = {
	LPI_PROTO_IRC,
	LPI_CATEGORY_CHAT,
	"IRC",
	2,
	match_irc
};

void register_irc(LPIModuleMap *mod_map) {
	register_protocol(&lpi_irc, mod_map );
}

