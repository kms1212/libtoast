/* Copyright (c) 2021. kms1212(Min Su Kwon)
This file is part of libtoast.

libtoast and its source code is published over BSD 3-Clause License.
See the BSD-3-Clause for more details.
<https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

*/

#include "libtoast/libtoast.h"

toast_file* toast_openfile(const char* filename, const int mode) {
    toast_file* ret = (toast_file*)malloc(sizeof(toast_file));

    if (mode == TOAST_DECODE) {
        // Open file
        ret->file_stream = fopen(filename, "r");
        if (ret->file_stream == NULL) {
            free(ret);
            ret = NULL;
            return ret;
        }

        // Check file validity
        if (toast_checkfile(ret)) {
            free(ret);
            ret = NULL;
            return ret;
        }
    } else if (mode == TOAST_ENCODE) {
        // Open file
        ret->file_stream = fopen(filename, "r+");
        if (ret->file_stream == NULL) {
            free(ret);
            ret = NULL;
            return ret;
        }
    }

    return ret;
}

void toast_closefile(toast_file* tfile) {
    fclose(tfile->file_stream);
    free(tfile);
}
