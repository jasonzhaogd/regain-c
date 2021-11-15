/**
 * 对数据进行字节级的解析和操作
 */

#ifndef REGAIN_C_INCLUDE_BYTE_UTILS_H_

#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int_bytes(int x) {
  show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float_bytes(float x) {
  show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer_bytes(void *x) {
  show_bytes((byte_pointer)&x, sizeof(void *));
}

#define REGAIN_C_INCLUDE_BYTE_UTILS_H_

#endif //REGAIN_C_INCLUDE_BYTE_UTILS_H_
