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

  riack_content_t *content = (riack_content_t*)malloc(sizeof(riack_content_t));
  rpb_content__init(content);
  
  
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
  char *val;
  char *cont_type;
  char *cont_encod;
  char *charset;
  va_start(args, content);
  while ((flag = va_arg(args, int)) != 0)
  {
    
    switch (flag) {
      case(-1) :
        break;
    case (RIACK_CONTENT_FIELD_VALUE):
      val = (char *)va_arg(args, char *);
      content->value.data = strdup(val);
      content->value.len = strlen(val);
      break;
    case (RIACK_CONTENT_FIELD_CONTENT_TYPE):
      cont_type = (char *)va_arg(args, char *);
      content->content_type.data = strdup(cont_type);
      content->content_type.len = strlen(cont_type);
      break;
    case (RIACK_CONTENT_FIELD_CONTENT_ENCODING):
      cont_encod = (char *)va_arg(args, char *);
      content->content_encoding.data = strdup(cont_encod);
      content->content_encoding.len = strlen(cont_encod);
      break;
    case (RIACK_CONTENT_FIELD_CHARSET):
      charset = (char *)va_arg(args, char *);
      content->charset.data = strdup(charset);
      content->charset.len = strlen(charset);
      break;
     }
  }
  if(flag == RIACK_CONTENT_FIELD_NONE)
    return 0;
     




}
