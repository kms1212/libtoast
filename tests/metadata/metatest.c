/* Copyright (c) 2021. kms1212(Min Su Kwon)
This file is part of libtoast.

libtoast and its source code is published over BSD 3-Clause License.
See the BSD-3-Clause for more details.
<https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

*/

#include <stdio.h>
#include <stdlib.h>

#include <libtoast/libtoast.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <testfile>\n", argv[0]);
        return 1;
    }

    toast_file* tfile = toast_openfile(argv[1], TOAST_DECODE);
    if (tfile == NULL) {
        fprintf(stderr, "Error opening file\n");
    }

    xmlChar* meta = (xmlChar*)malloc(tfile->file_info.toast_metasize + 1);
    memset(meta, 0, tfile->file_info.toast_metasize + 1);
    toast_getmeta(meta);

    fprintf(stdout, "OK\n");

    toast_closefile(tfile);
    return 0;
}