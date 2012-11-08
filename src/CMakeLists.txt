# -*- coding: utf-8 -*-
# ----------------------------------------------------------------------
# Copyright © 2011, RedJack, LLC.
# All rights reserved.
#
# Please see the LICENSE.txt file in this distribution for license
# details.
# ----------------------------------------------------------------------

include_directories(../include)

#-----------------------------------------------------------------------
# Build the library

set(LIBYARDARM_SRC
    libyardarm/c99.c
)

add_library(libyardarm SHARED ${LIBYARDARM_SRC})
set_target_properties(libyardarm PROPERTIES
    OUTPUT_NAME yardarm
    SOVERSION 0.0.0)
target_link_libraries(libyardarm
    ${CORK_LIBRARIES}
)

install(TARGETS libyardarm DESTINATION lib)

#-----------------------------------------------------------------------
# Generate the pkg-config file

set(prefix ${CMAKE_INSTALL_PREFIX})
configure_file(yardarm.pc.in yardarm.pc @ONLY)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/yardarm.pc
        DESTINATION lib/pkgconfig)
