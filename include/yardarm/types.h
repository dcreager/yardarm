/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_TYPES_H
#define YARDARM_TYPES_H

#include <libcork/core.h>


enum ya_kind {
    YA_KIND_POINTER,
    YA_KIND_SCALAR,
    YA_KIND_STRUCT,
    YA_KIND_UNION
};


struct ya_type {
    const char  *name;
    size_t  size;
    enum ya_kind  kind;
    const struct ya_type  *pointer;
};


#define YA_NAMED_SCALAR(c_type, name) \
    { name, sizeof(c_type), YA_KIND_SCALAR, NULL }

#define YA_SCALAR(c_type) \
    YA_NAMED_SCALAR(c_type, #c_type)

#define YA_NAMED_POINTER(c_type, ya_type, name) \
    { name, sizeof(c_type *), YA_KIND_POINTER, ya_type }

#define YA_POINTER(c_type, ya_type) \
    YA_NAMED_POINTER(c_type, ya_type, #c_type " *")

#endif /* YARDARM_TYPES_H */
