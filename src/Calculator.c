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

static int getFrequencyIndex(char numeral){
  return numeral - 'A';
}

static int checkForSubtraction(int frequencyArray[26], char numeral, int group){
   int isSubtraction = 0;
   if (frequencyArray[getFrequencyIndex(numeral)] == group){
      frequencyArray[getFrequencyIndex(numeral)]=frequencyArray[getFrequencyIndex(numeral)]-group;
      isSubtraction++;
   }
   return isSubtraction;
}

static void writeProperlyFormattedRomanNumeral(char* sortedReturnValue, int frequencyArray[26]){
   static const char ALL_ROMANS[] = "MDCLXVI";

   //Determine Substitutions
   int hasFour = checkForSubtraction(frequencyArray,'I',4);
   int hasFourty = checkForSubtraction(frequencyArray,'X',4);
   int hasFourHundred = checkForSubtraction(frequencyArray,'C',4);
   int hasNine = 0;  
   if (hasFour>0 && frequencyArray[getFrequencyIndex('V')] > 0){
      frequencyArray[getFrequencyIndex('V')]--;
      hasFour=0;
      hasNine++;
   }
   int hasNinty = 0;  
   if (hasFourty>0 && frequencyArray[getFrequencyIndex('L')] > 0){
      frequencyArray[getFrequencyIndex('L')]--;
      hasFourty=0;
      hasNinty++;
   }
   int hasNineHundred = 0;  
   if (hasFourHundred>0 && frequencyArray[getFrequencyIndex('D')] > 0){
      frequencyArray[getFrequencyIndex('D')]--;
      hasFourHundred=0;
      hasNineHundred++;
   }


   for (int d=0; ALL_ROMANS[d] != '\0'; d++) {
      for(int i=0; i<frequencyArray[getFrequencyIndex(ALL_ROMANS[d])]; i++ ){
          *sortedReturnValue++=ALL_ROMANS[d];
      }

      //write subtractions
      if (hasFour>0 && ALL_ROMANS[d] == 'I'){
          *sortedReturnValue++='I';
          *sortedReturnValue++='V';
      }
      if (hasNine>0 && ALL_ROMANS[d] == 'I'){
          *sortedReturnValue++='I';
          *sortedReturnValue++='X';
      }
      if (hasFourty>0 && ALL_ROMANS[d] == 'X'){
          *sortedReturnValue++='X';
          *sortedReturnValue++='L';
      }
      if (hasFourHundred>0 && ALL_ROMANS[d] == 'C'){
          *sortedReturnValue++='C';
          *sortedReturnValue++='D';
      }
      if (hasNinty>0 && ALL_ROMANS[d] == 'C'){
          *sortedReturnValue++='X';
          *sortedReturnValue++='C';
      }
      if (hasNineHundred>0 && ALL_ROMANS[d] == 'M'){
          *sortedReturnValue++='C';
          *sortedReturnValue++='M';
      }
   }
   *sortedReturnValue=0;
}

static void groupRomans(int frequencyArray[26]){
   if (frequencyArray[getFrequencyIndex('I')]>=5){
      frequencyArray[getFrequencyIndex('I')]=frequencyArray[getFrequencyIndex('I')]-5;
      frequencyArray[getFrequencyIndex('V')]++;
   }
   if (frequencyArray[getFrequencyIndex('V')]>=2){
      frequencyArray[getFrequencyIndex('V')]=frequencyArray[getFrequencyIndex('V')]-2;
      frequencyArray[getFrequencyIndex('X')]++;
   }
   if (frequencyArray[getFrequencyIndex('X')]>=5){
      frequencyArray[getFrequencyIndex('X')]=frequencyArray[getFrequencyIndex('X')]-5;
      frequencyArray[getFrequencyIndex('L')]++;
   }
   if (frequencyArray[getFrequencyIndex('L')]>=2){
      frequencyArray[getFrequencyIndex('L')]=frequencyArray[getFrequencyIndex('L')]-2;
      frequencyArray[getFrequencyIndex('C')]++;
   }
   if (frequencyArray[getFrequencyIndex('C')]>=5){
      frequencyArray[getFrequencyIndex('C')]=frequencyArray[getFrequencyIndex('C')]-5;
      frequencyArray[getFrequencyIndex('D')]++;
   }
   if (frequencyArray[getFrequencyIndex('D')]>=2){
      frequencyArray[getFrequencyIndex('D')]=frequencyArray[getFrequencyIndex('D')]-2;
      frequencyArray[getFrequencyIndex('M')]++;
   }
}

static void sortAndGroupRomans(char* sortedReturnValue, const char* concatinatedValue){
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
  sortAndGroupRomans(sortedReturnValue,concatinatedValue);

  return sortedReturnValue;
}