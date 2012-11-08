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
#include "yardarm/yardarm.h"


ya_declare_enum(
    yat_ya_kind,
    enum ya_kind,
    ya_enum_value(YA_KIND, ENUM),
    ya_enum_value(YA_KIND, POINTER),
    ya_enum_value(YA_KIND, SCALAR),
    ya_enum_value(YA_KIND, STRUCT),
    ya_enum_value(YA_KIND, UNION)
);
