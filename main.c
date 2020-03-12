/*
MIT License

Copyright (c) 2020 Cigan Oliviu David

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "dependencies/dataStructures.h"
#include <stdio.h>

typedef struct validationRules {

  int (*isNegative)(int * number);
  int (*isZero)(int * number);

} validationRules;

int isNegative (int * number) {

  if (*number < 0) return 1;

  return 0;
}

int isZero (int * number) {

  if (*number == 0) return 1;

  return 0;
}

typedef struct errorsHandler {

  int (*oneDimensionalArrayErrorsHandler)(oneDimensionalArrayType oneDimensionalArray);

} errorsHandler;

int oneDimensionalArrayErrorsHandler (oneDimensionalArrayType oneDimensionalArray) {

  validationRules __validations__ = { isNegative, isZero };

  if (isNegative(&oneDimensionalArray.length)) {
    printf("%s\n", "Unable to handler negative length");
    return 0;
  }

  if (isZero(&oneDimensionalArray.length)) {
    printf("%s\n", "Unable to handler length as zero");
    return 0;
  }

  return 1;
}

typedef struct binarySearchAlgorithms {

  int (*linearBinarySearch)(oneDimensionalArrayType oneDimensionalArray, int valueToSearch);

} binarySearchAlgorithms;

int linearBinarySearch (oneDimensionalArrayType oneDimensionalArray, int valueToSearch) {

  errorsHandler __handler__ = { oneDimensionalArrayErrorsHandler };

  __handler__.oneDimensionalArrayErrorsHandler (oneDimensionalArray);

  int leftIndex = oneDimensionalArray.startPoint;
  int rightIndex = oneDimensionalArray.length - 1;
  int middleIndex = oneDimensionalArray.startPoint;

  while (leftIndex <= rightIndex) {

    middleIndex = (leftIndex + rightIndex) / 2;

    if (valueToSearch == oneDimensionalArray.oneDimensionalArray_int_[middleIndex]) return 1;
    if (valueToSearch < oneDimensionalArray.oneDimensionalArray_int_[middleIndex]) rightIndex = middleIndex - 1;
    if (valueToSearch > oneDimensionalArray.oneDimensionalArray_int_[middleIndex]) leftIndex = middleIndex + 1;
  }

  return 0;
}

/* still for cheks */
void readOneDimensionalArray (oneDimensionalArrayType * oneDimensionalArray) {

  scanf("%d\n", &oneDimensionalArray->length);

  oneDimensionalArray->length -= 1;
  oneDimensionalArray->startPoint = 0;
  oneDimensionalArray->endPoint = 0;

  for (int it = oneDimensionalArray->startPoint; it < oneDimensionalArray->length + oneDimensionalArray->endPoint; it++)
      scanf("%d\n", &oneDimensionalArray->oneDimensionalArray_int_[it]);
}

void main (void) {

  oneDimensionalArrayType oneDimensionalArrayObject;

  binarySearchAlgorithms __algos__ = { linearBinarySearch };

  readOneDimensionalArray (& oneDimensionalArrayObject);

  printf("%d\n", __algos__.linearBinarySearch (oneDimensionalArrayObject, 31));
}
