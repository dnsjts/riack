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

#include "riack/platform.h"

#include <riack/client.h>

const char *
riack_version (void)
{
  return PACKAGE_VERSION;
}

const char *
riack_version_string (void)
{
  return PACKAGE_STRING;
}

riack_client_t *
riack_client_new (void)
{
}

int
riack_client_free (riack_client_t *client)
{
}

int
riack_client_connect (riack_client_t *client, ...)
{
}

int
riack_client_disconnect (riack_client_t *client)
{
}
