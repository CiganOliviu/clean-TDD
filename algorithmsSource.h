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

#include "validationRules/validationRules.h"
#include "coreFunctionalitiesDependency/algorithmsSourceDefinition.h"


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

int maxDivideEtEmpera (oneDimensionalArrayType oneDimensionalArray, limits interval) {

  errorsHandler __handler__ = { oneDimensionalArrayErrorsHandler };

  __handler__.oneDimensionalArrayErrorsHandler (oneDimensionalArray);

  int parameterOne, parameterTwo, middleIndex;
  limits rightWing;
  limits leftWing;

  if (interval.minimLimit_int_ == interval.maximLimit_int_)  return oneDimensionalArray.oneDimensionalArray_int_[interval.minimLimit_int_];
  else {

    middleIndex = (interval.minimLimit_int_ + interval.maximLimit_int_) / 2;

    leftWing.minimLimit_int_ = interval.minimLimit_int_;
    leftWing.maximLimit_int_ = middleIndex;

    rightWing.minimLimit_int_ = middleIndex + 1;
    rightWing.maximLimit_int_ = interval.maximLimit_int_;

    parameterOne = maxDivideEtEmpera (oneDimensionalArray, leftWing);
    parameterTwo = maxDivideEtEmpera (oneDimensionalArray, rightWing);

    if (parameterOne > parameterTwo) return parameterOne;
    else return parameterTwo;
  }
}

int minDivideEtEmpera (oneDimensionalArrayType oneDimensionalArray, limits interval) {

  errorsHandler __handler__ = { oneDimensionalArrayErrorsHandler };

  __handler__.oneDimensionalArrayErrorsHandler (oneDimensionalArray);

  int parameterOne, parameterTwo, middleIndex;
  limits rightWing;
  limits leftWing;

  if (interval.minimLimit_int_ == interval.maximLimit_int_)  return oneDimensionalArray.oneDimensionalArray_int_[interval.minimLimit_int_];
  else {

    middleIndex = (interval.minimLimit_int_ + interval.maximLimit_int_) / 2;

    leftWing.minimLimit_int_ = interval.minimLimit_int_;
    leftWing.maximLimit_int_ = middleIndex;

    rightWing.minimLimit_int_ = middleIndex + 1;
    rightWing.maximLimit_int_ = interval.maximLimit_int_;

    parameterOne = minDivideEtEmpera (oneDimensionalArray, leftWing);
    parameterTwo = minDivideEtEmpera (oneDimensionalArray, rightWing);

    if (parameterOne < parameterTwo) return parameterOne;
    else return parameterTwo;
  }
}
