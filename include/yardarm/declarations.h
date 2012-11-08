/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2012, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef YARDARM_DECLARATIONS_H
#define YARDARM_DECLARATIONS_H

#include <yardarm/types.h>


#define ya_declare_type(name) \
    extern const struct ya_type  name;


#define ya_declare_enum(ya_name, c_type, ...) \
    static const struct ya_value  ya_name##__values[] = { \
        __VA_ARGS__ \
    }; \
    const struct ya_type  ya_name = { \
        #c_type, sizeof(c_type), YA_KIND_ENUM, \
        sizeof(ya_name##__values) / sizeof(ya_name##__values[0]), \
        NULL, ya_name##__values \
    }

#define ya_named_enum_value(prefix, suffix, name) \
    { #name, #suffix, name }

#define ya_enum_value(prefix, suffix) \
    ya_named_enum_value(prefix, suffix, prefix##_##suffix)

#define ya_declare_named_scalar(ya_name, c_type, name) \
    const struct ya_type  ya_name = { \
        name, sizeof(c_type), YA_KIND_SCALAR, 0, NULL, NULL \
    }

#define ya_declare_scalar(ya_name, c_type) \
    ya_declare_named_scalar(ya_name, c_type, #c_type)

#define ya_declare_named_pointer(ya_name, c_type, pointer, name) \
    const struct ya_type  ya_name = { \
        name, sizeof(c_type *), YA_KIND_POINTER, 0, pointer, NULL \
    }

#define ya_declare_pointer(ya_name, c_type, pointer) \
    ya_declare_named_pointer(ya_name, c_type, pointer, #c_type " *")


#endif /* YARDARM_DECLARATIONS_H */
