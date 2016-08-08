#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char* add(const char* val1, const char* val2){
  int len =strlen(val1)+strlen(val1)+1;
  char* sum=malloc(len);
  strcpy(sum,val1);
  strcat(sum,val2);
  return sum;
}
