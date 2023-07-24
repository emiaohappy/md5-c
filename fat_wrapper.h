//
// Created by macwe on 2023-07-24.
//

#ifndef MD5_C_FAT_H
#define MD5_C_FAT_H

typedef enum {
    FAT_FLAG_READ = FA_READ,
    FAT_FLAG_WRITE = FA_WRITE,
    FAT_FLAG_OPEN_EXISTING = FA_OPEN_EXISTING,
    FAT_FLAG_CREATE_NEW = FA_CREATE_NEW,
    FAT_FLAG_CREATE_ALWAYS = FA_CREATE_ALWAYS,
    FAT_FLAG_OPEN_ALWAYS = FA_OPEN_ALWAYS,
    FAT_FLAG_OPEN_APPEND = FA_OPEN_APPEND,
} fat_flag_e;

#define FAT_FPRINTF(fp, fmt, ...) f_printf(fp, fmt, ##__VA_ARGS__)

typedef FATFS fat_fs_t;

extern void
fat_1_init();

extern int
fat_file_open(fat_file_t *file, const char *path, uint8_t mode);

extern int
fat_file_close(fat_file_t *file);

extern int
fat_file_read(fat_file_t *file, void *buff, size_t size, size_t *done_size);

extern int
fat_file_write(fat_file_t *file, void *buff, size_t size, size_t *done_size);

extern int
fat_file_truncate(fat_file_t *file);

extern int
fat_file_seek(fat_file_t *file, size_t offset);

extern uint32_t
fat_file_tell(fat_file_t *file);

extern int
fat_file_sync(fat_file_t *file);

extern int
fat_file_delete(const char *path);

extern size_t
get_fat_file_size(fat_file_t *file);

extern int
fat_fs_mount(fat_fs_t *fs, const char *path);

extern int
fat_fs_unmount(const char *path);

extern int
fat_file_stat(const char *path, fat_file_info_t *info);

#endif //MD5_C_FAT_H
