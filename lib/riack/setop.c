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

#include <riack/setop.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

riack_setop_t *
riack_setop_new (void)
{
  riack_setop_t *setop = (riack_setop_t*)malloc(sizeof(riack_setop_t));
  set_op__init(setop);
  return setop;
}

void 
riack_setop_free (riack_setop_t *setop)
{
  set_op__free_unpacked(setop,NULL);
}


int 
riack_setop_set (riack_setop_t *setop, ...)
{

  va_list args;
  char *adds;
  char *removes;
  int flag;
  int flagadd;
  
  if (setop == NULL)
    return -EINVAL;
  
  
  va_start(args, setop);
  while ((flag = va_arg(args, int)) != RIACK_SETOP_FIELD_NONE)
  {
    
    switch (flag) {
      
      case (RIACK_SETOP_FIELD_ADD):
        //while ((flagadd = va_arg(args, int)) != RIACK_SETOP_FIELD_REMOVE) 
        //{
        if(setop->adds[0].data)
          free(setop->adds[0].data);
        adds = (char *)va_arg(args, char *);
        if (adds) {
          //setop->adds = malloc(sizeof(adds));
          setop->adds[0].data =strdup(adds);
          setop->adds[0].len = strlen(adds);
          }
        
        break;
      case (RIACK_SETOP_FIELD_REMOVE):
        //while ((flagadd = va_arg(args, int)) != RIACK_SETOP_FIELD_ADD) 
        //{
        if(setop->removes[0].data)
          free(setop->removes[0].data);
        removes = (char *)va_arg(args, char *);
        if (adds) {
          
          setop->removes[0].data =strdup(removes);
          setop->removes[0].len = strlen(removes);
          }
       
        break;
    }
  }
  if(flag == RIACK_SETOP_FIELD_NONE)
    return 0;
     
}
