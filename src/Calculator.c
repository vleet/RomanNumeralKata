#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char* add(const char* val1, const char* val2){
  //Concatinate
  int len =strlen(val1)+strlen(val1)+1;
  char* concatinatedValue=malloc(len);
  strcpy(concatinatedValue,val1);
  strcat(concatinatedValue,val2);

   //Sort
  char* sortedReturnValue=malloc(strlen(concatinatedValue)+1);
   int c = 0, count[26] = {0};
   while (concatinatedValue[c] != '\0')
   {
      count[concatinatedValue[c]-'A']++;
      c++;
   }
 
   static const char ALL_ROMANS[] = "MDCLXVI";
   int d = 0;
   char* p=sortedReturnValue;
   while (ALL_ROMANS[d] != '\0')
   {
      if ( count[ALL_ROMANS[d]-'A'] > 0 ){
          *p++=ALL_ROMANS[d];
      }
        d++;
    } 
    *p=0;
  return sortedReturnValue;
}