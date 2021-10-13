/**
 * 用函数递归和迭代两种方法实现阶乘，但是阶乘的案例看不出两种实现的效率差距，
 * 隔壁斐波那契的例子很方便看出两种实现的效率差距
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * 递归的实现
 * @param n
 * @return
 */
unsigned int FactorialRecursion(unsigned int n);

/**
 * 迭代的实现
 * @param n
 * @return
 */
unsigned int FactorialIteration(unsigned int n);

int main(void) {
  printf("3! = %u  --recursion\n", FactorialRecursion(3));
  printf("3! = %u  --iteration\n", FactorialIteration(3));

  printf("5! = %u  --recursion\n", FactorialRecursion(5));
  printf("5! = %u  --iteration\n", FactorialIteration(5));

  printf("10! = %u  --recursion\n", FactorialRecursion(10));
  printf("10! = %u  --iteration\n", FactorialIteration(10));

  printf("33! = %u  --recursion\n", FactorialRecursion(33));
  printf("33! = %u  --iteration\n", FactorialIteration(33));

  return EXIT_SUCCESS;
}

unsigned int FactorialRecursion(unsigned int n) {
  if (n == 0) {
    return 1;
  }
  return n * FactorialRecursion(n - 1);
}

unsigned int FactorialIteration(unsigned int n) {
  unsigned int result = 1;
  for (unsigned int i = n; i > 0; --i) {
    result *= i;
  }
  return result;
}