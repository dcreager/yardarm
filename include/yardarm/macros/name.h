/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_MACROS_NAME_H
#define YARDARM_MACROS_NAME_H


#define ya_get_name(yad)  yad(ya_get_name_)
#define ya_get_name_(kind, ...)  ya_get_name__##kind(__VA_ARGS__)

#define ya_get_name__enum_start(ya_name, c_type)  #c_type
#define ya_get_name__named_enum_value(loc, ya_name, prefix, suffix, name) \
    /* skip */
#define ya_get_name__enum_value(loc, ya_name, prefix, suffix)  /* skip */
#define ya_get_name__enum_end(ya_name, c_type)  /* skip */

#define ya_get_name__named_pointer(ya_name, ref_name, name)  name
#define ya_get_name__pointer(ya_name, ya_ref)   ya_get_name(yad(ya_ref)) " *"

#define ya_get_name__named_scalar(ya_name, c_type, name)  name
#define ya_get_name__scalar(ya_name, c_type)   #c_type


#endif /* YARDARM_MACROS_NAME_H */
