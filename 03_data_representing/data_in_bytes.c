/**
 * 看看各种数据在字节层面的表示
 */

#include <stdio.h>
#include <stdlib.h>

#include "../include/byte_utils.h"

int main(void) {
  printf("int value 12345 is present in bytes:");
  show_int_bytes(12345);

  printf("float value 12345.0 is present in bytes:");
  show_float_bytes(12345.0f);

  printf("point &main is present in bytes:");
  show_pointer_bytes(main);

  return EXIT_SUCCESS;
}

