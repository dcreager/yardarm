/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_DESCRIPTORS_H
#define YARDARM_DESCRIPTORS_H

#include <libcork/core.h>


enum ya_kind {
    YA_KIND_ENUM,
    YA_KIND_POINTER,
    YA_KIND_SCALAR,
    YA_KIND_STRUCT,
    YA_KIND_UNION
};


struct ya_value {
    const char * const  name;
    const char * const  short_name;
    long  value;
};

struct ya_type {
    const char * const  name;
    size_t  size;
    enum ya_kind  kind;
    size_t  child_count;
    const struct ya_type * const  pointer;
    const struct ya_value * const  values;
};


#endif /* YARDARM_DESCRIPTORS_H */
