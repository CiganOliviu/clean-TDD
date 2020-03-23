#include "../main.h"

typedef struct processAndValidateData {

  void (*readOneDimensionalArray)(char * fileName, oneDimensionalArrayType * oneDimensionalArray);
  void (*returnEvaluation)(int evaluation);

} processAndValidateData;

void readOneDimensionalArray (char * fileName, oneDimensionalArrayType * oneDimensionalArray) {

  oneDimensionalArray->startPoint = 0;
  oneDimensionalArray->endPoint = 0;

  FILE * file;
  file = fopen(fileName, "r");

  fileValidation (file);

  fscanf (file, "%d ", &oneDimensionalArray->length);

  for (int iterator = 0; iterator < oneDimensionalArray->length; iterator++)
    fscanf (file, "%d", &oneDimensionalArray->oneDimensionalArray_int_[iterator]);

  oneDimensionalArray->length -= 1;

  fclose(file);
}

void returnEvaluation (int evaluation) {

  if (evaluation == 1)
    printf("%s\n", "Test passed");
  else
    printf("%s\n", "Test unpassed");
}

void main (void) {

  oneDimensionalArrayType oneDimensionalArrayObject;

  processAndValidateData __process__ = { readOneDimensionalArray, returnEvaluation };
  divideEtEmperaAlgorithms __algos__ = { linearBinarySearch, maxDivideEtEmpera , minDivideEtEmpera};
  limits interval;

  __process__.readOneDimensionalArray ((char*)"data/stream.data", & oneDimensionalArrayObject);

  __process__.returnEvaluation ( __algos__.linearBinarySearch (oneDimensionalArrayObject, 435) );

/*
  interval.minimLimit_int_ = oneDimensionalArrayObject.startPoint;
  interval.maximLimit_int_ = oneDimensionalArrayObject.length;

  printf("%d\n", __algos__.minDivideEtEmpera (oneDimensionalArrayObject, interval));

  */
}
