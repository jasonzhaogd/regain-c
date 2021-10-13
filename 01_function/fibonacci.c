/**
 * 用递归和迭代分别实现斐波那契，可以很明显看出递归耗资源和时间的特性
 * f(n) = f(n - 1) + f(n - 2)
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * 递归实现
 */
unsigned int FibonacciRecursion(unsigned int n);

/**
 * 迭代实现
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

/**
 * 递给形式代码可读性太好了！
 */
unsigned int FibonacciRecursion(unsigned int n) {
  if (n == 1 || n == 0) {
    return n;
  }
  return FibonacciRecursion(n - 1) + FibonacciRecursion(n - 2);
}

/**
 * 用迭代的方式来实现 f(n) = f(n - 1) + f(n - 2) 还是有些难理解的
 */
unsigned int FibonacciIteration(unsigned int n) {
  if (n == 1 || n == 0) {
    return n; // f(0) = 1, f(1) = 1
  }

  // 其实只要看表达式的右边，牵涉到两个值，而不是 3 个值。
  unsigned int last = 0;
  unsigned int result = 1;

  // 迭代的总体实现是控制循环次数
  // 因为前两个数 0 和 1 的返回值是固定的，所以是少循环两次, 直接从 2 开始循环
  // f(2) = f(1) + f(0) 接着
  // f(3) = f(2) + f(1)
  for (int i = 0; i <= n - 2; ++i) {
    unsigned temp;
    temp = result;
    result += last;
    last = temp;
  }

  return result;
}