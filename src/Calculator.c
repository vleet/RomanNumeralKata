#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

static void concatRomans(char* concatinatedValue, const char* val1, const char* val2){
  //Concatinate
  strcpy(concatinatedValue,val1);
  strcat(concatinatedValue,val2);
}

static void determineRomanFrequency(int frequencyArray[26], const char* concatinatedValue){
   int c = 0;
   while (concatinatedValue[c] != '\0')
   {
      frequencyArray[concatinatedValue[c]-'A']++;
      c++;
   }
 }

static void writeProperlyFormattedRomanNumeral(char* sortedReturnValue, const int count[26]){
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

}

static void sortRomans(char* sortedReturnValue, const char* concatinatedValue){
   int count[26] = {0};
   determineRomanFrequency(count,concatinatedValue);
   writeProperlyFormattedRomanNumeral(sortedReturnValue,count);
}

char* add(const char* val1, const char* val2){

  int len =strlen(val1)+strlen(val1)+1;
  char* concatinatedValue=malloc(len);
  concatRomans(concatinatedValue,val1,val2);

  char* sortedReturnValue=malloc(strlen(concatinatedValue)+1);
  sortRomans(sortedReturnValue,concatinatedValue);

  return sortedReturnValue;
}