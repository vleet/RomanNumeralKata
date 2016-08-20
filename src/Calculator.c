#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "globals.h"

//static const char ALL_ROMANS[] = "MDCLXVI";
static const char ALL_ROMANS[7] = {'M','D','C','L','X','V','I'};
static const char ALL_ROMANS_ASSENDING[] = "IVXLCDM";

static void concatRomans(char* concatinatedValue, const char* val1, const char* val2){
  //Concatinate
  strcpy(concatinatedValue,val1);
  strcat(concatinatedValue,val2);
}

static int getFrequencyIndex(char numeral){
  char theNumeral[2]={numeral,'\0'};

  if (strstr(ALL_ROMANS,(char *)&theNumeral) != NULL){
    return numeral - 'A';
  }
  return 0;
}

static void determineRomanFrequency(int frequencyArray[26], const char* concatinatedValue){
   for (int c = 0; concatinatedValue[c] != '\0'; c++) {
      frequencyArray[getFrequencyIndex(concatinatedValue[c])]++;
   }
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

   if(frequencyArray[getFrequencyIndex(ROMAN_M)] > 3){ 
    *sortedReturnValue++='\0';
    return;
   }

   //Determine Substitutions
   int hasFour = checkForSubtraction(frequencyArray,ROMAN_I,4);
   int hasFourty = checkForSubtraction(frequencyArray,ROMAN_X,4);
   int hasFourHundred = checkForSubtraction(frequencyArray,ROMAN_C,4);
   int hasNine = 0;  
   if (hasFour>0 && frequencyArray[getFrequencyIndex(ROMAN_V)] > 0){
      frequencyArray[getFrequencyIndex(ROMAN_V)]--;
      hasFour=0;
      hasNine++;
   }
   int hasNinty = 0;  
   if (hasFourty>0 && frequencyArray[getFrequencyIndex(ROMAN_L)] > 0){
      frequencyArray[getFrequencyIndex(ROMAN_L)]--;
      hasFourty=0;
      hasNinty++;
   }
   int hasNineHundred = 0;  
   if (hasFourHundred>0 && frequencyArray[getFrequencyIndex(ROMAN_D)] > 0){
      frequencyArray[getFrequencyIndex(ROMAN_D)]--;
      hasFourHundred=0;
      hasNineHundred++;
   }


   for (int d=0; d < sizeof(ALL_ROMANS); d++) {
      for(int i=0; i<frequencyArray[getFrequencyIndex(ALL_ROMANS[d])]; i++ ){
          *sortedReturnValue++=ALL_ROMANS[d];
      }

      //write subtractions
      if (hasFour>0 && ALL_ROMANS[d] == ROMAN_I){
          *sortedReturnValue++=ROMAN_I;
          *sortedReturnValue++=ROMAN_V;
      }
      if (hasNine>0 && ALL_ROMANS[d] == ROMAN_I){
          *sortedReturnValue++=ROMAN_I;
          *sortedReturnValue++=ROMAN_X;
      }
      if (hasFourty>0 && ALL_ROMANS[d] == ROMAN_X){
          *sortedReturnValue++=ROMAN_X;
          *sortedReturnValue++=ROMAN_L;
      }
      if (hasFourHundred>0 && ALL_ROMANS[d] == ROMAN_C){
          *sortedReturnValue++=ROMAN_C;
          *sortedReturnValue++=ROMAN_D;
      }
      if (hasNinty>0 && ALL_ROMANS[d] == ROMAN_C){
          *sortedReturnValue++=ROMAN_X;
          *sortedReturnValue++=ROMAN_C;
      }
      if (hasNineHundred>0 && ALL_ROMANS[d] == ROMAN_M){
          *sortedReturnValue++=ROMAN_C;
          *sortedReturnValue++=ROMAN_M;
      }
   }
   *sortedReturnValue=0;
}
static void writeExpandedRomanNumeral(char* sortedReturnValue, int frequencyArray[26]){
   for (int d=0; d < sizeof(ALL_ROMANS); d++) {
      for(int i=0; i<frequencyArray[getFrequencyIndex(ALL_ROMANS[d])]; i++ ){
          *sortedReturnValue++=ALL_ROMANS[d];
      }
   }
   *sortedReturnValue=0;
}

static void groupRomans(int frequencyArray[26]){
   if (frequencyArray[getFrequencyIndex(ROMAN_I)]>=5){
      frequencyArray[getFrequencyIndex(ROMAN_I)]=frequencyArray[getFrequencyIndex(ROMAN_I)]-5;
      frequencyArray[getFrequencyIndex(ROMAN_V)]++;
   }
   if (frequencyArray[getFrequencyIndex(ROMAN_V)]>=2){
      frequencyArray[getFrequencyIndex(ROMAN_V)]=frequencyArray[getFrequencyIndex(ROMAN_V)]-2;
      frequencyArray[getFrequencyIndex(ROMAN_X)]++;
   }
   if (frequencyArray[getFrequencyIndex(ROMAN_X)]>=5){
      frequencyArray[getFrequencyIndex(ROMAN_X)]=frequencyArray[getFrequencyIndex(ROMAN_X)]-5;
      frequencyArray[getFrequencyIndex(ROMAN_L)]++;
   }
   if (frequencyArray[getFrequencyIndex(ROMAN_L)]>=2){
      frequencyArray[getFrequencyIndex(ROMAN_L)]=frequencyArray[getFrequencyIndex(ROMAN_L)]-2;
      frequencyArray[getFrequencyIndex(ROMAN_C)]++;
   }
   if (frequencyArray[getFrequencyIndex(ROMAN_C)]>=5){
      frequencyArray[getFrequencyIndex(ROMAN_C)]=frequencyArray[getFrequencyIndex(ROMAN_C)]-5;
      frequencyArray[getFrequencyIndex(ROMAN_D)]++;
   }
   if (frequencyArray[getFrequencyIndex(ROMAN_D)]>=2){
      frequencyArray[getFrequencyIndex(ROMAN_D)]=frequencyArray[getFrequencyIndex(ROMAN_D)]-2;
      frequencyArray[getFrequencyIndex(ROMAN_M)]++;
   }
}

static void sortAndGroupRomans(char* sortedReturnValue, const char* concatinatedValue){
   int count[26] = {0};
   determineRomanFrequency(count,concatinatedValue);
   groupRomans(count);
   writeProperlyFormattedRomanNumeral(sortedReturnValue,count);
}
static int calculateLength(const int frequencyArray[26]){
  int len=0;
     for (int c = 0; c<26; c++) {
        len = len + frequencyArray[c];
   }
   return len;
}

static char* removeSubstitutions(const char* val1){
  int frequencyArray[26] = {0};
  determineRomanFrequency(frequencyArray,val1);

  if (strstr(val1, "IV") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_I)]=frequencyArray[getFrequencyIndex(ROMAN_I)]+3;
    frequencyArray[getFrequencyIndex(ROMAN_V)]--;
  }
  if (strstr(val1, "IX") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_I)]=frequencyArray[getFrequencyIndex(ROMAN_I)]+3;
    frequencyArray[getFrequencyIndex('V')]++;
    frequencyArray[getFrequencyIndex('X')]--;
  }
  if (strstr(val1, "XL") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_X)]=frequencyArray[getFrequencyIndex(ROMAN_X)]+3;
    frequencyArray[getFrequencyIndex(ROMAN_L)]--;
  }
  if (strstr(val1, "CD") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_C)]=frequencyArray[getFrequencyIndex(ROMAN_C)]+3;
    frequencyArray[getFrequencyIndex(ROMAN_D)]--;
  }
  if (strstr(val1, "XC") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_X)]=frequencyArray[getFrequencyIndex(ROMAN_X)]+3;
    frequencyArray[getFrequencyIndex(ROMAN_L)]++;
    frequencyArray[getFrequencyIndex(ROMAN_C)]--;
  }
  if (strstr(val1, "CM") != NULL) { 
    frequencyArray[getFrequencyIndex(ROMAN_C)]=frequencyArray[getFrequencyIndex(ROMAN_C)]+3;
    frequencyArray[getFrequencyIndex(ROMAN_D)]++;
    frequencyArray[getFrequencyIndex(ROMAN_M)]--;
  }

  char* expandedValue=malloc(calculateLength(frequencyArray));
  writeExpandedRomanNumeral(expandedValue,frequencyArray);   

  return expandedValue;
}

static void getMoreNumerals(int arrayToAdjust[26],const char numeralNeeded){
  if (numeralNeeded == ROMAN_I){
      if (arrayToAdjust[getFrequencyIndex(ROMAN_V)] == 0){
         getMoreNumerals(arrayToAdjust,getFrequencyIndex(ROMAN_V));
      }
      arrayToAdjust[getFrequencyIndex(ROMAN_I)]=arrayToAdjust[getFrequencyIndex(ROMAN_I)]+5;
      arrayToAdjust[getFrequencyIndex(ROMAN_V)]--;
  }
  if (numeralNeeded == ROMAN_V){
      if (arrayToAdjust[getFrequencyIndex(ROMAN_X)] == 0){
         getMoreNumerals(arrayToAdjust,getFrequencyIndex(ROMAN_X));
      }
      arrayToAdjust[getFrequencyIndex(ROMAN_V)]=arrayToAdjust[getFrequencyIndex(ROMAN_V)]+2;
      arrayToAdjust[getFrequencyIndex(ROMAN_X)]--;
  }
  if (numeralNeeded == ROMAN_X){
      if (arrayToAdjust[getFrequencyIndex(ROMAN_L)] == 0){
         getMoreNumerals(arrayToAdjust,getFrequencyIndex(ROMAN_L));
      }
      arrayToAdjust[getFrequencyIndex(ROMAN_X)]=arrayToAdjust[getFrequencyIndex(ROMAN_X)]+5;
      arrayToAdjust[getFrequencyIndex(ROMAN_L)]--;
  }
  if (numeralNeeded == ROMAN_L){
      if (arrayToAdjust[getFrequencyIndex(ROMAN_C)] == 0){
         getMoreNumerals(arrayToAdjust,getFrequencyIndex(ROMAN_C));
      }
      arrayToAdjust[getFrequencyIndex(ROMAN_L)]=arrayToAdjust[getFrequencyIndex(ROMAN_L)]+2;
      arrayToAdjust[getFrequencyIndex(ROMAN_C)]--;
  }
  if (numeralNeeded == ROMAN_C){
      if (arrayToAdjust[getFrequencyIndex(ROMAN_D)] == 0){
         getMoreNumerals(arrayToAdjust,getFrequencyIndex(ROMAN_D));
      }
      arrayToAdjust[getFrequencyIndex(ROMAN_C)]=arrayToAdjust[getFrequencyIndex(ROMAN_C)]+5;
      arrayToAdjust[getFrequencyIndex(ROMAN_D)]--;
  }
  if (numeralNeeded == ROMAN_D){
      arrayToAdjust[getFrequencyIndex(ROMAN_D)]=arrayToAdjust[getFrequencyIndex(ROMAN_D)]+2;
      arrayToAdjust[getFrequencyIndex(ROMAN_M)]--;
  }
}

static void subtractFrequencies(int difference[26] ,int leftNumeral[26] ,int rightNumeral[26] ){
   for (int d=0; ALL_ROMANS_ASSENDING[d] != '\0'; d++) {
      if (leftNumeral[getFrequencyIndex(ALL_ROMANS_ASSENDING[d])]<rightNumeral[getFrequencyIndex(ALL_ROMANS_ASSENDING[d])]){
          getMoreNumerals(leftNumeral, ALL_ROMANS_ASSENDING[d]);
      }
      for (int i=rightNumeral[getFrequencyIndex(ALL_ROMANS_ASSENDING[d])]; i < leftNumeral[getFrequencyIndex(ALL_ROMANS_ASSENDING[d])]; i++ ){
          difference[getFrequencyIndex(ALL_ROMANS_ASSENDING[d])]++;
      }
    }
}

static int wouldProduceNegativeResult(const int left[], const int right[]){
   for (int d=0; d < sizeof(ALL_ROMANS); d++) {
       if (right[getFrequencyIndex(ALL_ROMANS[d])] < left[getFrequencyIndex(ALL_ROMANS[d])]){
          return 0;
       }
       if (right[getFrequencyIndex(ALL_ROMANS[d])] > left[getFrequencyIndex(ALL_ROMANS[d])]){
          return 1;
       }
    }
    return 1;
}


char* add(const char* val1, const char* val2){

  int len =strlen(val1)+strlen(val1)+1;
  char* concatinatedValue=malloc(len);
  concatRomans(concatinatedValue,removeSubstitutions(val1),removeSubstitutions(val2));

  char* sortedReturnValue=malloc(strlen(concatinatedValue)+1);
  sortAndGroupRomans(sortedReturnValue,concatinatedValue);

  return sortedReturnValue;
}

char* subtract(const char* val1, const char* val2){
   int leftNumeral[26] = {0};
   determineRomanFrequency(leftNumeral,removeSubstitutions(val1));
   int rightNumeral[26] = {0};
   determineRomanFrequency(rightNumeral,removeSubstitutions(val2));

   if (wouldProduceNegativeResult(leftNumeral,rightNumeral) != 0) {
        return "";
   }

   int difference[26] = {0};
   subtractFrequencies(difference,leftNumeral,rightNumeral);

   char* returnValue=malloc(calculateLength(difference));
   groupRomans(difference);
   writeProperlyFormattedRomanNumeral(returnValue,difference);
  return returnValue;
}

