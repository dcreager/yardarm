/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_MACROS_DESCRIPTORS_H
#define YARDARM_MACROS_DESCRIPTORS_H

#include <yardarm/descriptors.h>
#include <yardarm/macros/basics.h>
#include <yardarm/macros/name.h>


#define ya_declare_type(yad)  yad(ya_declare_type_)
#define ya_declare_type_(kind, ...)  ya_declare_type__##kind(__VA_ARGS__)

#define ya_declare_type__enum_start(ya_name, c_type) \
    extern const struct ya_type  yat(ya_name);
#define ya_declare_type__named_enum_value(ya_name, prefix, suffix, name) \
    /* skip */
#define ya_declare_type__enum_value(ya_name, prefix, suffix) \
    /* skip */
#define ya_declare_type__enum_end(ya_name, c_type) \
    /* skip */

#define ya_declare_type__pointer(ya_name, ref_name) \
    extern const struct ya_type  yat(ya_name);

#define ya_declare_type__named_scalar(ya_name, c_type, name) \
    extern const struct ya_type  yat(ya_name);
#define ya_declare_type__scalar(ya_name, c_type) \
    extern const struct ya_type  yat(ya_name);


#define ya_define_type(yad)  yad(ya_define_type_)
#define ya_define_type_(kind, ...)  ya_define_type__##kind(__VA_ARGS__)

#define ya_define_type__enum_start(ya_name, c_type) \
    static const struct ya_value  ya_name##__values[] = {
#define ya_define_type__named_enum_value(ya_name, prefix, suffix, name) \
        { #name, #suffix, name },
#define ya_define_type__enum_value(ya_name, prefix, suffix) \
    ya_define_type__named_enum_value(ya_name, prefix, suffix, prefix##_##suffix)
#define ya_define_type__enum_end(ya_name, c_type) \
    }; \
    const struct ya_type  yat(ya_name) = { \
        #c_type, sizeof(c_type), YA_KIND_ENUM, \
        (sizeof(ya_name##__values) / sizeof(ya_name##__values[0])), \
        NULL, ya_name##__values \
    }

#define ya_define_type__named_pointer(ya_name, ref_name, name) \
    const struct ya_type  yat(ya_name) = { \
        name, sizeof(void *), YA_KIND_POINTER, 0, &yat(ref_name), NULL \
    }
#define ya_define_type__pointer(ya_name, ref_name) \
    ya_define_type__named_pointer(ya_name, ref_name, \
                                  ya_get_name__pointer(ya_name, ref_name))

#define ya_define_type__named_scalar(ya_name, c_type, name) \
    const struct ya_type  yat(ya_name) = { \
        name, sizeof(c_type), YA_KIND_SCALAR, 0, NULL, NULL \
    }
#define ya_define_type__scalar(ya_name, c_type) \
    ya_define_type__named_scalar(ya_name, c_type, \
                                 ya_get_name__scalar(ya_name, c_type))


#endif /* YARDARM_MACROS_DESCRIPTORS_H */
