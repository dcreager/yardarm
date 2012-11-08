/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include <libcork/core.h>

#include "yardarm/c99.h"
#include "yardarm/types.h"


#define ___(name, c_type) \
const struct ya_type  yat_##name = \
    YA_NAMED_SCALAR(c_type, #c_type); \
const struct ya_type  yat_##name##_p = \
    YA_NAMED_POINTER(c_type, &yat_##name, #c_type " *");
ya_all_c99_types(___);
#undef ___
