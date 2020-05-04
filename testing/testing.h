#include "../algorithmsSource.h"

typedef struct lowLevelProcessing {

  void (*readOneDimensionalArray)(char * fileName, oneDimensionalArrayType * oneDimensionalArray);
  void (*outputOneDimensionalArray)(oneDimensionalArrayType oneDimensionalArray);

} lowLevelProcessing;

void readOneDimensionalArray(char * fileName, oneDimensionalArrayType * oneDimensionalArray);
void outputOneDimensionalArray(oneDimensionalArrayType oneDimensionalArray);

typedef struct dataNormalisation {

  void (*interchangeValues)(int * parameterOne, int * parameterTwo);
  void (*sortData)(oneDimensionalArrayType * oneDimensionalArray);

} dataNormalisation;

void interchangeValues(int * parameterOne, int * parameterTwo);
void sortData(oneDimensionalArrayType * oneDimensionalArray);

typedef struct assertions {

  int (*valueAssertion)(int returnedValue, int expectedValue);
  void (*logEvaluation)(int evaluation);

} assertions;

int valueAssertion(int returnedValue, int expectedValue);
void logEvaluation(int evaluation);
