# Copyright (c) 2021. kms1212(Min Su Kwon)
# This file is part of libtoast.
# 
# libtoast and its source code is published over BSD 3-Clause License.
# See the BSD-3-Clause for more details.
# <https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

cmake_minimum_required(VERSION 3.12)

set(NO_BUILD false CACHE BOOL "Skip build?")

if(NOT NO_BUILD)
    set(BUILD_TESTS true CACHE BOOL "Build tests?")

    #########################
    # DEPENDENCIES
    #########################
    find_package(LibXml2 REQUIRED)

    #########################
    # PROJECT OPTIONS
    #########################
    project("toast")
    string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
    string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
    set(TARGET_NAME ${PROJECT_NAME_LOWER})
    
    #########################
    # BUILD OPTIONS
    #########################
    set(CMAKE_C_STANDARD_REQUIRED ON)
    set(CMAKE_C_STANDARD          99)
    set(CMAKE_C_EXTENSIONS        OFF)

    #########################
    # CHECK HEADERS/SYMBOLS FOR LIBRARY
    #########################
    include(CheckIncludeFile)
    include(CheckSymbolExists)
    include(CheckTypeSize)

    check_include_file("stdio.h"  STDIO_H_FOUND)
    check_include_file("stdlib.h" STDLIB_H_FOUND)
    check_include_file("stdint.h" STDINT_H_FOUND)
    check_include_file("string.h" STRING_H_FOUND)

    #########################
    # BUILD LIBRARY
    #########################
    file(GLOB ${TARGET_NAME}_SOURCES "${CMAKE_SOURCE_DIR}/src/*")
    add_library(
        ${TARGET_NAME} # binary name
        SHARED
        ${${TARGET_NAME}_SOURCES}) # source files

    target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/>)
    target_include_directories(
        ${TARGET_NAME}
        PUBLIC
        ${LIBXML2_INCLUDE_DIR})
    target_link_libraries(
        ${TARGET_NAME}
        LibXml2::LibXml2)

    #########################
    # BUILD TESTS
    #########################
    if (BUILD_TESTS)
        add_subdirectory(tests)
    endif()
endif()