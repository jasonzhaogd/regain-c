/**
* 用递归和迭代分别实现斐波那契，可以很明显看出递归耗资源和时间的特性
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 递归实现
 * @param n
 * @return
 */
unsigned int FibonacciRecursion(unsigned int n);

/**
 * 迭代实现
 * @param n
 * @return
 */
unsigned int FibonacciIteration(unsigned int n);

int main(void) {
  printf("Fib(3) = %u  --recursion\n", FibonacciRecursion(3));
  printf("Fib(3) = %u  --iteration\n", FibonacciIteration(3));

  printf("Fib(6) = %u  --recursion\n", FibonacciRecursion(6));
  printf("Fib(6) = %u  --iteration\n", FibonacciIteration(6));

  printf("Fib(10) = %u  --recursion\n", FibonacciRecursion(10));
  printf("Fib(10) = %u  --iteration\n", FibonacciIteration(10));

  puts("用递归的方式还是很耗资源的，当计算斐波那契数列第 50 个元素时，用递归的方式需要 2 分钟左右才能得到结果。。。");
  printf("Fib(50) = %u  --recursion\n", FibonacciRecursion(50));
  puts("而同样是计算斐波那契第 50 个元素，迭代的方式实现是秒出的：");
  printf("Fib(50) = %u  --iteration\n", FibonacciIteration(50));

  return EXIT_SUCCESS;
}

unsigned int FibonacciRecursion(unsigned int n) {
  if (n == 1 || n == 0) {
    return n;
  }
  return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

unsigned int FibonacciIteration(unsigned int n) {
  unsigned int result = 0, result_prev = 0, result_prev_prev = 0;

  for (int i = 0; i < n; ++i) {
    if (i == 0 || i == 1) {
      result = i;
    }
    result_prev = result;
    result += result_prev_prev;
    result_prev_prev = result_prev;
  }

  return result;
}