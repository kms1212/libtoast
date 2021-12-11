/* Copyright (c) 2021. kms1212(Min Su Kwon)
This file is part of libtoast.

libtoast and its source code is published over BSD 3-Clause License.
See the BSD-3-Clause for more details.
<https://raw.githubusercontent.com/kms1212/libtoast/main/LICENSE>

*/

#include "libtoast/libtoast.h"

#pragma pack(push, 1)
struct __t_file_header {
    uint8_t      signature[5];
    uint16_t     version;
    uint8_t      __reserved1;
    uint16_t     filetype;
    uint16_t     filemode;
    uint8_t      __reserved2[4];
    uint64_t     metastart;
    uint64_t     metasize;
    uint64_t     datastart;
    uint64_t     datasize;
};
#pragma pack(pop)

int toast_checkfile(toast_file* tfile) {
    struct __t_file_header header;
    size_t read_count =
        fread(&header, sizeof(struct __t_file_header), 1, tfile->file_stream);

    if (memcmp(header.signature, "TOAST", 5) != 0) {
        return 1;
    }

    tfile->file_info.toast_version = header.version;
    tfile->file_info.toast_filetype = header.filetype;
    tfile->file_info.toast_filemode = header.filemode;
    tfile->file_info.toast_metasize = header.metasize;
    tfile->file_info.toast_datasize = header.datasize;

    return 0;
}
