/* Pi-hole: A black hole for Internet advertisements
*  (c) 2019 Pi-hole, LLC (https://pi-hole.net)
*  Network-wide ad blocking via your own hardware.
*
*  FTL Engine
*  File prototypes
*
*  This file is copyright under the latest version of the EUPL.
*  Please see LICENSE file for your rights under this license. */
#ifndef FILE_H
#define FILE_H

bool chmod_file(const char *filename, const mode_t mode);
bool file_exists(const char *filename);
unsigned long long get_FTL_db_filesize(void);
void ls_dir(const char* path);

#endif //FILE_H
