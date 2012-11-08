/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_YARDARM_H
#define YARDARM_YARDARM_H

#include <yardarm/macros/descriptors.h>


#define yad_ya_kind(_) \
    _(enum_start, ya_kind, enum ya_kind) \
    _(enum_value, first,  ya_kind, YA_KIND, ENUM) \
    _(enum_value, middle, ya_kind, YA_KIND, POINTER) \
    _(enum_value, middle, ya_kind, YA_KIND, SCALAR) \
    _(enum_value, middle, ya_kind, YA_KIND, STRUCT) \
    _(enum_value, last,   ya_kind, YA_KIND, UNION) \
    _(enum_end, ya_kind, enum ya_kind)

ya_declare_type(yad_ya_kind);


#endif /* YARDARM_YARDARM_H */
