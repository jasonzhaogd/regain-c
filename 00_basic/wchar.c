/**
 * 测试宽字符的处理
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(void) {
  char a = 'a';
  printf("a = %c\n", a);
  wprintf(L"a = %c\n", a);


  setlocale(LC_ALL, "");
  wchar_t b = L'中';
  wprintf(L"b = %lc", b);
  printf("\n");
  printf("b 的编码 = %d\n", b);

  // 宽字符串
  wchar_t wide_string[] = L"中国";
  wprintf(L"wide_string = %ls\n", wide_string);

  return EXIT_SUCCESS;
}