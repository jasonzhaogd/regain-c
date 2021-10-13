/**
 * 函数的边长参数，固定套路用法
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void TestVarargs(int arg_count, ...) {
  // 1. 定义 va_list 类型的变量，用于获取传入的变长参数
  va_list args;

  // 2. 开始遍历
  // 注意 va_start 的第二个参数是要求我们指明变长参数之前的那个有名字的参数。
  // that is the last parameter that has an explicit name (as opposed to vararg parameters, which have no names).
  // You need to pass the last named parameter to va_start in order for it to figure out the address in memory
  // at which the vararg parameters start.
  va_start(args, arg_count);

  for (int i = 0; i < arg_count; ++i) {
    // 3. 依次取出对应参数， va_arg 的函数原型是 va_arg(va_list, type)
    int arg = va_arg(args, int);
    printf("第%d个参数是：%d\n", i+1, arg);
  }

  // 4. 结束遍历
  va_end(args);
}

int main(void) {
  TestVarargs(5, 11, 22, 33);
  puts("");
  TestVarargs(5, 11, 22, 33, 44, 55, 66, 77, 88, 99);
  return EXIT_SUCCESS;
}

