#include "../main.h"

typedef struct processAndValidateData {

  void (*readOneDimensionalArray)(oneDimensionalArrayType * oneDimensionalArray);

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

void main (void) {

  oneDimensionalArrayType oneDimensionalArrayObject;

  processAndValidateData __process__ = { readOneDimensionalArray };
  binarySearchAlgorithms __algos__ = { linearBinarySearch };

  __process__.readOneDimensionalArray ((char*)"data/stream.data", & oneDimensionalArrayObject);

  printf("%d\n", __algos__.linearBinarySearch (oneDimensionalArrayObject, 435));
}
