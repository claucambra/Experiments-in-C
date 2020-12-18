#include <stdio.h>

int times_tabler(int num1, int num2) {
  char output[30];
  int count, multiplied;

  for(count = 1; count <= num2; count++) {
    multiplied = num1*count;
    printf("%i x %i = %i\n", num1, count, multiplied);
  }

  return 0;
}

int main() {
  int numToMultiply, timesTableLimit;
  puts("Input a number.");
  scanf("%d[^\n]\n", &numToMultiply);
  puts("Up to which number would you like your times table to go?");
  scanf("%d[^\n]\n", &timesTableLimit);

  times_tabler(numToMultiply, timesTableLimit);

  return 0;
}
