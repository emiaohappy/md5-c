#ifndef MD5_H
#define MD5_H

#include "fat_wrapper.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_SIZE_T uint32_t
#define INPUT_BUFF_LEN (64)

typedef struct {
    INPUT_SIZE_T size;        // Size of input in bytes
    uint32_t buffer[4];   // Current accumulation of hash
    uint8_t input[INPUT_BUFF_LEN];    // Input to be used in the next step
    uint8_t digest[16];   // Result of algorithm
} MD5Context;

void md5Init(MD5Context *ctx);

void md5Update(MD5Context *ctx, const uint8_t *input_buffer, size_t input_len);

void md5Finalize(MD5Context *ctx);

void md5Step(uint32_t *buffer, uint32_t *input);

void md5String(char *input, uint8_t *result);

void md5File(fat_file_t *file, uint8_t *result);

#endif
