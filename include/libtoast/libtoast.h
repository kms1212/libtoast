/* Copyright (c) 2021. kms1212(Min Su Kwon)
This file is part of libtoast.

libtoast and its source code is published over BSD 3-Clause License.
See the BSD-3-Clause for more details.
<https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

*/

#ifndef LIBTOAST_LIBTOAST_H_
#define LIBTOAST_LIBTOAST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

#define TOAST_DECODE 1
#define TOAST_ENCODE 2

////////////////////////////////////////////////////
// Types / Structs
////////////////////////////////////////////////////

typedef size_t toast_time;

struct toast_fileinfo {
    uint16_t     toast_version;
    uint16_t     toast_filetype;
    uint16_t     toast_filemode;
    uint64_t     toast_metasize;
    uint64_t     toast_datasize;
};

typedef struct toast_file {
    FILE*                 file_stream;
    struct toast_fileinfo file_info;
} toast_file;

////////////////////////////////////////////////////
// File operations
////////////////////////////////////////////////////
/**
 * @brief Open toast container file
 * 
 * @param filename: Full path of target file
 * @param mode: Open mode
 * @return toast_file*: File struct
 * @details
 * param mode:
 * - TOAST_DECODE: Opens file with mode "r"
 * - TOAST_ENCODE: Opens file with mode "w" and creates header automatically.
 */
toast_file* toast_openfile(const char* filename, const int mode);

/**
 * @brief Close toast container file
 * 
 * @param tfile: File struct
 */
void toast_closefile(toast_file* tfile);

////////////////////////////////////////////////////
// File structure operations
////////////////////////////////////////////////////
/**
 * 
 */
int toast_checkfile(toast_file* tfile);

int toast_getmeta(xmlChar* buf);

#endif  // LIBTOAST_LIBTOAST_H_
