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

static inline bool match_line_request(uint32_t payload, uint32_t len) {

        /* This packet varies in length but is always ~680 bytes if we
         * end up needing a stronger rule */
        if (MATCH(payload, 0x80, 0x02, 0x00, 0x01))
                return true;

        if (len == 12 && MATCH(payload, 0x80, 0x02, 0x00, 0x06))
                return true;

        return false;

}

static inline bool match_line_response(uint32_t payload, uint32_t len) {

        if (len == 60 && MATCH(payload, 0x80, 0x02, 0x00, 0x04))
                return true;

        return false;

}

static inline bool match_line(lpi_data_t *data, lpi_module_t *mod UNUSED) {

        /* Restrict to port 443 for now */
        if (data->server_port != 443 && data->client_port != 443)
                return false;

        /* This looks a lot like an SSL 2.0 handshake */
        if (match_line_request(data->payload[0], data->payload_len[0])) {
                if (match_line_response(data->payload[1], data->payload_len[1]))
                        return true;
        }

        if (match_line_request(data->payload[1], data->payload_len[1])) {
                if (match_line_response(data->payload[0], data->payload_len[0]))
                        return true;
        }

	return false;
}

static lpi_module_t lpi_line = {
	LPI_PROTO_LINE,
	LPI_CATEGORY_CHAT,
	"Line",
	12,
	match_line
};

void register_line(LPIModuleMap *mod_map) {
	register_protocol(&lpi_line, mod_map );
}

