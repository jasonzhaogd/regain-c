/**
 * 宏函数和预定义宏的使用
 * 用普通函数和宏函数对比一个简单的打印行的功能
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * 普通函数的实现，要借用 va_* 变长参数的一系列宏。
 */
void PrintLine(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

#define PRINT_LINE(format, ...) printf("("__FILE__":%d) [%s] - "format"\n", __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define PRINT_INT(value) PRINT_LINE(#value" = %d", value)

int main(void) {
  PrintLine("Hello function! %d, %lf", 2, 3.14);

  PRINT_LINE("Hello macro! %d, %lf", 2, 3.14);
  PRINT_LINE("Hello String literal");

  PRINT_INT(2);
  PRINT_INT(3 + 4);
  int x = 5;
  PRINT_INT(x);

  return EXIT_SUCCESS;
}
