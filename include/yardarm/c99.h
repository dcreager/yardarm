/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_C99_H
#define YARDARM_C99_H

#include <libcork/core.h>

#include <yardarm/declarations.h>
#include <yardarm/types.h>


#define ya_all_c99_types(_) \
    _(bool,    bool) \
    _(char,    char) \
    _(short,   short) \
    _(int,     int) \
    _(long,    long) \
    _(uchar,   unsigned char) \
    _(ushort,  unsigned short) \
    _(uint,    unsigned int) \
    _(ulong,   unsigned long) \
    _(int8,    int8_t) \
    _(int16,   int16_t) \
    _(int32,   int32_t) \
    _(int64,   int64_t) \
    _(intptr,  intptr_t) \
    _(ssize,   ssize_t) \
    _(uint8,   uint8_t) \
    _(uint16,  uint16_t) \
    _(uint32,  uint32_t) \
    _(uint64,  uint64_t) \
    _(uintptr, uintptr_t) \
    _(size,    size_t) \
    _(float,   float) \
    _(double,  double) \


#define ___(name, c_type) \
    ya_declare_type(yat_##name); \
    ya_declare_type(yat_##name##_p);
ya_all_c99_types(___);
#undef ___


#endif /* YARDARM_C99_H */
