#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *str = NULL;
  while (get_next_line(0, &str) > 0){
    printf("%s\n", str);
    free(str);
  }
  return (0);
}
