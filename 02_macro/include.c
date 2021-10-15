/**
 * 测试包含头文件，以及测试 io_utils 中的工具宏定义是否能正常使用
*/

#include <stdio.h>
#include <stdlib.h>
#define PRINT_METADATA
#include "../include/io_utils.h"

int main(void) {
  PRINT_CHAR('W');
  PRINT_WCHAR(L'赵');
  PRINT_INT(4);
  PRINT_LONG(100L);
  PRINT_LONGLONG(1000LL);
  PRINT_HEX(0xFF);
  PRINT_BOOL(-1);
  PRINT_DOUBLE(3.14159267);
  PRINT_STRING("Hello C");
  PRINT_WSTRING(L"Hello 中国");

  int arr_int[] = {1, 2, 3, 4, 5};
  // 注意，宏函数调用后面是否加分号，是不一定的，要看宏函数定义时最后是否已经加了分号或者需不需要。
  PRINT_INT_ARRAY(arr_int, 5)
  PRINT_INT_ARRAY_PER_LINE(arr_int, 5)

  int arr_ch[] = {'j', 'a', 's', 'o', 'n'};
  PRINT_CHAR_ARRAY(arr_ch, 10)

  double arr_double[] = {1.0, 2.0, 3.0, 4.7};
  PRINT_DOUBLE_ARRAY(arr_double, 10)

  return EXIT_SUCCESS;
}
