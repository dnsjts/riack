/* riack -- Riak C client library
 * Copyright (C) 2015  Gergely Nagy <algernon@madhouse-project.org>
 * Copyright (C) 2015  Parth Oberoi <htrapdev@gmail.com>
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file lib/riack/client.h
 */

/** @defgroup riack_client Riak Client
 *
 *
 * @addtogroup riack_client
 * @{
 */

#ifndef __RIACK_CLIENT_H__
#define __RIACK_CLIENT_H__

#ifdef __cplusplus
extern "C" {
#endif

/** The Riak client object.
 *
 * This is an opaque class, the internal state of the Riak client.
 */
typedef struct _riack_client_t riack_client_t;

/** Return the library version.
 *
 * @returns the compiled-in library version as a string.
 */
const char *riack_version (void);
/** Return the library name and version.
 *
 * @returns the compiled-in library name and version, as a string.
 */
const char *riack_version_string (void);

/** Allocate a new, unconnected client.
 *
 * Use riack_client_connect() to connect the newly created client to a
 * server.
 *
 * @returns a newly allocated riack_client_t object, which must be
 * freed with riack_client_free() once no longer needed.
 */
riack_client_t *riack_client_new (void);

/** Free a Riak client object.
 *
 * Disconnects and frees up the supplied client.
 *
 * @param client is the client object to free up.
 *
 * @retval -EINVAL if client is NULL.
 * @retval -ENOTCONN if the client was not connected.
 * @retval 0 on success.
 *
 * @note The object will be freed even in case of non-fatal errors.
 */
int riack_client_free (riack_client_t *client);

#ifdef __cplusplus
} /* extern "C" */
#endif

/** @} */

#endif
