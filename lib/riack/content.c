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

#include <riack/content.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>


riack_content_t *
riack_content_new (void)
{

  riack_content_t *content;
  content =(riack_content_t*)malloc(sizeof(riack_content_t));

  return content;
}

void
riack_content_free (riack_content_t *content)
{
  free(content);
}

int
riack_content_set (riack_content_t *content, ...)
{
  va_list args;
  if (content == NULL)
    return -EINVAL;
  int flag;  
  va_start(args, content);
  while (flag = va_arg(args, int) != 0)
  {
    char *val = "";
    if (flag == -1)
      continue;
    if (flag == 1) {
      sprintf(val, "%s",va_arg(args, char *));
      content.value.data = strdup(val);
      content.value.len = strlen(val);
      }
    else if (flag == 2) {
      sprintf(val, "%s",va_arg(args, char *));
      content.content_type.data = strdup(val);
      content.content_type.len = strlen(val);
      }
    else if (flag == 3) {
      sprintf(val, "%s",va_arg(args, char *));
      content.content_encoding.data = strdup(val);
      content.content_encoding.len = strlen(val);
      }
    else if (flag == 4) {
      sprintf(val, "%s",va_arg(args, char *));
      content.charset.data = strdup(val);
      content.charset.len = strlen(val);
      }
  }
  if(flag == 0)
    return 0;
     




}
