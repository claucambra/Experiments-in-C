#include <stdio.h>
#include <stdlib.h>

int line_build(int count_num, int height_num) {
  char line[101];
  int column_count, column_count_pt2;
  for(column_count = 0; column_count <= height_num; column_count++){
    if(column_count > height_num-count_num) {
      line[column_count] = '*';
    } else {
      line[column_count] = ' ';
    }
  }
  for(column_count_pt2 = 1; column_count_pt2 < count_num; column_count_pt2++, column_count++){
    line[column_count] = '*';
  }

  printf("%s\n", line);

  return 0;
}


int main(int argc, char *argv[]) {
  if(argc > 3) {
    puts("Too many arguments. Please only specify height.");
    return 1;
  }

  char ch;
  int height = atoi(argv[2]);

  while (height > 19 || height < 1) {
    printf("%i is not a valid height. Pyramids can be between 1 and 19 lines high.\n");
    return 2;
  }

  printf("Pyramid with height of %i lines.", height);

  int count;
  for(count = 0; count <= height; count++) {
    line_build(count, height);
  }

  return 0;
}
