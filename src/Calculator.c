#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char* add(const char* val1, const char* val2){
  int len =strlen(val1)+strlen(val1)+1;
  char* concatinatedValue=malloc(len);
  if ('V' == *val1) {
		strcpy(concatinatedValue,val1);
	  	strcat(concatinatedValue,val2);
	}
  else{
  		strcpy(concatinatedValue,val2);
  		strcat(concatinatedValue,val1);
 	} 
  return concatinatedValue;
}
