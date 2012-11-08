/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#include "yardarm/c99.h"
#include "yardarm/macros/descriptors.h"


#define ___(name, c_type) \
    ya_define_type(yad_##name); \
    ya_define_type(yad_##name##_p);
ya_all_c99_types(___);
#undef ___
