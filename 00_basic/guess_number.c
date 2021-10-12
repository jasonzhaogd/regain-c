/**
* 猜数字的游戏
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int magic_number = rand();
//  printf("magic number is %d\n", magic_number);

  while (1) {
    int user_input;

    puts("Please inout a number:");
    scanf("%d", &user_input);
    if (user_input > magic_number) {
      printf("Your number is bigger! %f\n", user_input * 1.f / magic_number);
    } else if (user_input < magic_number) {
      printf("Your number is smaller! %f\n", user_input * 1.f / magic_number);
    } else {
      puts("Yes, you got it!");
      break;
    }
  }

  return EXIT_SUCCESS;
}