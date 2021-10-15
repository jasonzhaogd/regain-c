/**
 * 标准输出的调试工具宏定义
*/

#ifndef REGAIN_C_INCLUDE_IO_UTILS_H_
#define REGAIN_C_INCLUDE_IO_UTILS_H_

#include <stdio.h>
#include <locale.h>
#include <wchar.h>

#ifdef PRINT_METADATA
#define PRINT_LINE(format, ...) printf(__FILE__":%d [%s] - "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define PRINT_LINE_WCHAR(format, ...) setlocale(LC_ALL, ""); wprintf(L""__FILE__":%d [%s] - "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define PRINT_LINE(format, ...) printf(format"\n", ##__VA_ARGS__)
#define PRINT_LINE_WCHAR(format, ...) setlocale(LC_ALL, ""); wprintf(L""format"\n", ##__VA_ARGS__)
#endif

#define PRINT_CHAR(value) PRINT_LINE(#value" = %c", value)
#define PRINT_WCHAR(value) PRINT_LINE_WCHAR(#value" = %lc", value)
#define PRINT_INT(value) PRINT_LINE(#value" = %d", value)
#define PRINT_LONG(value) PRINT_LINE(#value" = %ld", value)
#define PRINT_LONGLONG(value) PRINT_LINE(#value" = %lld", value)
#define PRINT_HEX(value) PRINT_LINE(#value" = %#x", value)
#define PRINT_BOOL(value) PRINT_LINE(#value" = %s", value ? "true" : "false")
#define PRINT_DOUBLE(value) PRINT_LINE(#value" = %g", value)
#define PRINT_STRING(value) PRINT_LINE(#value" = %s", value)
#define PRINT_WSTRING(value) PRINT_LINE_WCHAR(#value" = %ls", value)

#ifdef PRINT_METADATA
#define PRINT_ARRAY(format, array, length)                              \
{                                                                       \
  printf(__FILE__":%d [%s] - "#array"[] = ", __LINE__, __FUNCTION__);   \
  for(int i = 0; i < length; ++i) {                                     \
    printf(format, array[i]);                                           \
  };                                                                    \
printf("\n");                                                           \
}
#else
#define PRINT_ARRAY(format, array, length)                              \
{                                                                       \
  printf(#array"[] = ");                                                \
  for(int i = 0; i < length; ++i) {                                     \
    printf(format, array[i]);                                           \
  };                                                                    \
printf("\n");                                                           \
}
#endif

#define PRINT_INT_ARRAY_PER_LINE(array, length)         \
{                                                       \
  for(int i = 0; i < length; ++i) {                     \
    PRINT_LINE(#array"[%d] = %d", i, array[i]);         \
  }                                                     \
}

#define PRINT_INT_ARRAY(array, length) PRINT_ARRAY("%d, ", array, length)
#define PRINT_CHAR_ARRAY(array, length) PRINT_ARRAY("%c, ", array, length)
#define PRINT_DOUBLE_ARRAY(array, length) PRINT_ARRAY("%lf, ", array, length)

#endif // REGAIN_C_INCLUDE_IO_UTILS_H_
