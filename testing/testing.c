#include "../algorithmsSource.h"

typedef struct lowLevelProcessing {

  void (*readOneDimensionalArray)(char * fileName, oneDimensionalArrayType * oneDimensionalArray);
  void (*outputOneDimensionalArray)(oneDimensionalArrayType oneDimensionalArray);

} lowLevelProcessing;

void readOneDimensionalArray (char * fileName, oneDimensionalArrayType * oneDimensionalArray) {

  oneDimensionalArray->startPoint = 0;
  oneDimensionalArray->endPoint = 0;

  FILE * file;
  file = fopen(fileName, "r");

  fileValidation (file);

  fscanf (file, "%d ", &oneDimensionalArray->length);

  for (int iterator = oneDimensionalArray->startPoint; iterator < oneDimensionalArray->length + oneDimensionalArray->endPoint; iterator++)
    fscanf (file, "%d", &oneDimensionalArray->oneDimensionalArray_int_[iterator]);

  oneDimensionalArray->length -= 1;

  fclose(file);
}

void outputOneDimensionalArray (oneDimensionalArrayType oneDimensionalArray) {

  errorsHandler __handler__ = { oneDimensionalArrayErrorsHandler };

  __handler__.oneDimensionalArrayErrorsHandler (oneDimensionalArray);

  for (int iterator = oneDimensionalArray.startPoint; iterator < oneDimensionalArray.length + oneDimensionalArray.endPoint; iterator++)
    printf("%d ", oneDimensionalArray.oneDimensionalArray_int_[iterator]);
}

typedef struct dataNormalisation {

  void (*interchangeValues)(int * parameterOne, int * parameterTwo);
  void (*sortData)(oneDimensionalArrayType * oneDimensionalArray);

} dataNormalisation;

void interchangeValues (int * parameterOne, int * parameterTwo) {

  *parameterOne = *parameterOne + *parameterTwo;
  *parameterTwo = *parameterOne - *parameterTwo;
  *parameterOne = *parameterOne - *parameterTwo;
}

void sortData (oneDimensionalArrayType * oneDimensionalArray) {

  for (int iterator = oneDimensionalArray->startPoint; iterator < oneDimensionalArray->length + oneDimensionalArray->endPoint - 1; iterator++)
    for (size_t jiterator = oneDimensionalArray->startPoint; jiterator < oneDimensionalArray->length + oneDimensionalArray->endPoint - iterator - 1; jiterator++)
      if (oneDimensionalArray->oneDimensionalArray_int_[jiterator] > oneDimensionalArray->oneDimensionalArray_int_[jiterator + 1])
        interchangeValues (&oneDimensionalArray->oneDimensionalArray_int_[jiterator], &oneDimensionalArray->oneDimensionalArray_int_[jiterator + 1]);
}

typedef struct assertions {

  int (*valueAssertion)(int returnedValue, int expectedValue);
  void (*logEvaluation)(int evaluation);

} assertions;

int valueAssertion (int returnedValue, int expectedValue) {

  if (returnedValue == expectedValue) return 1;

  return 0;
}

void logEvaluation (int evaluation) {

  if (evaluation == 1)
    printf("%s\n", "Test passed");
  else
    printf("%s\n", "Test unpassed");
}

void main (void) {

  oneDimensionalArrayType oneDimensionalArrayObject;

  lowLevelProcessing __processing__ = { readOneDimensionalArray, outputOneDimensionalArray };
  dataNormalisation __normalisation__ = { interchangeValues, sortData };
  assertions __assertions__ = { valueAssertion, logEvaluation };
  divideEtEmperaAlgorithms __divideEtEmpera__ = { linearBinarySearch, maxDivideEtEmpera , minDivideEtEmpera};
  limits interval;

  __processing__.readOneDimensionalArray ((char*)"data/stream.data", & oneDimensionalArrayObject);
  __processing__.outputOneDimensionalArray (oneDimensionalArrayObject);

  printf("%s\n", "");

  __normalisation__.sortData (& oneDimensionalArrayObject);
  __processing__.outputOneDimensionalArray (oneDimensionalArrayObject);

  printf("%s\n", "");

  __assertions__.logEvaluation ( __divideEtEmpera__.linearBinarySearch (oneDimensionalArrayObject, 435) );

  interval.minimLimit_int_ = oneDimensionalArrayObject.startPoint;
  interval.maximLimit_int_ = oneDimensionalArrayObject.length;

  __assertions__.logEvaluation ( __assertions__.valueAssertion (__divideEtEmpera__.minDivideEtEmpera (oneDimensionalArrayObject, interval), 1) );
  __assertions__.logEvaluation ( __assertions__.valueAssertion (__divideEtEmpera__.maxDivideEtEmpera (oneDimensionalArrayObject, interval), 8762) );
}
