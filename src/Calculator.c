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
   for (int c = 0; concatinatedValue[c] != '\0'; c++) {
      frequencyArray[concatinatedValue[c]-'A']++;
   }
 }

static void writeProperlyFormattedRomanNumeral(char* sortedReturnValue, const int count[26]){
   static const char ALL_ROMANS[] = "MDCLXVI";

   char* p=sortedReturnValue;
   for (int d=0; ALL_ROMANS[d] != '\0'; d++) {
      for(int i=0; i<count[ALL_ROMANS[d]-'A']; i++ ){
          *p++=ALL_ROMANS[d];
      }
    } 
    *p=0;

}

static void groupRomans(int frequencyArray[26]){
   if (frequencyArray['I'-'A']>=5){
      frequencyArray['I'-'A']=frequencyArray['I'-'A']-5;
      frequencyArray['V'-'A']++;
   }
}

static void sortRomans(char* sortedReturnValue, const char* concatinatedValue){
   int count[26] = {0};
   determineRomanFrequency(count,concatinatedValue);
   groupRomans(count);
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