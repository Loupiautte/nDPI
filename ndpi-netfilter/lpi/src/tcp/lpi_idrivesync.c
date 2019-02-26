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

static inline bool match_idrivesync_hello(uint32_t payload) {

        if (MATCH(payload, '@', 'I', 'D', 'E'))
                return true;
        return false;

}

static inline bool match_idrivesync(lpi_data_t *data, lpi_module_t *mod UNUSED) {

        if (match_idrivesync_hello(data->payload[0])) {
                if (match_idrivesync_hello(data->payload[1]))
                        return true;
                if (data->payload_len[1] == 0)
                        return true;
        }

        if (match_idrivesync_hello(data->payload[1])) {
                if (data->payload_len[0] == 0)
                        return true;
        }

	return false;
}

static lpi_module_t lpi_idrivesync = {
	LPI_PROTO_IDRIVE_SYNC,
	LPI_CATEGORY_CLOUD,
	"IDriveSync",
	5,
	match_idrivesync
};

void register_idrivesync(LPIModuleMap *mod_map) {
	register_protocol(&lpi_idrivesync, mod_map );
}
