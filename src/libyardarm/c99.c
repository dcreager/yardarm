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
#include "yardarm/declarations.h"
#include "yardarm/types.h"


#define ___(name, c_type) \
ya_declare_named_scalar(yat_##name, c_type, #c_type); \
ya_declare_named_pointer(yat_##name##_p, c_type, &yat_##name, #c_type " *");
ya_all_c99_types(___);
#undef ___
