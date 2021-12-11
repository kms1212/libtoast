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
        return 1;
    }

    printf("toast_version: %d\n", tfile->file_info.toast_version);
    printf("toast_filetype: %d\n", tfile->file_info.toast_filetype);
    printf("toast_filemode: %d\n", tfile->file_info.toast_filemode);
    printf("toast_metasize: %I64d\n", tfile->file_info.toast_metasize);
    printf("toast_datasize: %I64d\n", tfile->file_info.toast_datasize);

    toast_closefile(tfile);
    return 0;
}