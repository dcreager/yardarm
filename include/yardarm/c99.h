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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#include <yardarm/macros/descriptors.h>


#define yad_bool(_)     yad_bool_(_)
#define yad_bool_(_)    _(named_scalar, bool_, bool, "bool")
#define yad_char(_)     _(scalar, char, char)
#define yad_short(_)    _(scalar, short, short)
#define yad_int(_)      _(scalar, int, int)
#define yad_long(_)     _(scalar, long, long)

#define yad_uchar(_)    _(scalar, uchar, unsigned char)
#define yad_ushort(_)   _(scalar, ushort, unsigned short)
#define yad_uint(_)     _(scalar, uint, unsigned int)
#define yad_ulong(_)    _(scalar, ulong, unsigned long)

#define yad_int8(_)     _(scalar, int8, int8_t)
#define yad_int16(_)    _(scalar, int16, int16_t)
#define yad_int32(_)    _(scalar, int32, int32_t)
#define yad_int64(_)    _(scalar, int64, int64_t)
#define yad_intptr(_)   _(scalar, intptr, intptr_t)
#define yad_ssize(_)    _(scalar, ssize, ssize_t)

#define yad_uint8(_)    _(scalar, uint8, uint8_t)
#define yad_uint16(_)   _(scalar, uint16, uint16_t)
#define yad_uint32(_)   _(scalar, uint32, uint32_t)
#define yad_uint64(_)   _(scalar, uint64, uint64_t)
#define yad_uintptr(_)  _(scalar, uintptr, uintptr_t)
#define yad_size(_)     _(scalar, size, size_t)

#define yad_float(_)    _(scalar, float, float)
#define yad_double(_)   _(scalar, double, double)


#define yad_bool_p(_)     _(pointer, bool_p, bool_)
#define yad_char_p(_)     _(pointer, char_p, char)
#define yad_short_p(_)    _(pointer, short_p, short)
#define yad_int_p(_)      _(pointer, int_p, int)
#define yad_long_p(_)     _(pointer, long_p, long)

#define yad_uchar_p(_)    _(pointer, uchar_p, uchar)
#define yad_ushort_p(_)   _(pointer, ushort_p, ushort)
#define yad_uint_p(_)     _(pointer, uint_p, uint)
#define yad_ulong_p(_)    _(pointer, ulong_p, ulong)

#define yad_int8_p(_)     _(pointer, int8_p, int8)
#define yad_int16_p(_)    _(pointer, int16_p, int16)
#define yad_int32_p(_)    _(pointer, int32_p, int32)
#define yad_int64_p(_)    _(pointer, int64_p, int64)
#define yad_intptr_p(_)   _(pointer, intptr_p, intptr)
#define yad_ssize_p(_)    _(pointer, ssize_p, ssize)

#define yad_uint8_p(_)    _(pointer, uint8_p, uint8)
#define yad_uint16_p(_)   _(pointer, uint16_p, uint16)
#define yad_uint32_p(_)   _(pointer, uint32_p, uint32)
#define yad_uint64_p(_)   _(pointer, uint64_p, uint64)
#define yad_uintptr_p(_)  _(pointer, uintptr_p, uintptr)
#define yad_size_p(_)     _(pointer, size_p, size)

#define yad_float_p(_)    _(pointer, float_p, float)
#define yad_double_p(_)   _(pointer, double_p, double)


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


#define yat_bool  yat_bool_

#define ___(name, c_type) \
    ya_declare_type(yad_##name); \
    ya_declare_type(yad_##name##_p);
ya_all_c99_types(___);
#undef ___


#endif /* YARDARM_C99_H */
