# Copyright (c) 2021. kms1212(Min Su Kwon)
# This file is part of libtoast.
# 
# libtoast and its source code is published over BSD 3-Clause License.
# See the BSD-3-Clause for more details.
# <https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

cmake_minimum_required(VERSION 3.12)

project("signature_test")

add_executable(${PROJECT_NAME} signtest.c)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} toast)
add_dependencies(${PROJECT_NAME} toast)

add_test(NAME ${PROJECT_NAME}
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/testvideo.toa)