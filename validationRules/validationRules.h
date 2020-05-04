#include "validationRulesDefinition.h"

int isNegative (int * number) {

  if (*number < 0) return 1;

  return 0;
}

int isZero (int * number) {

  if (*number == 0) return 1;

  return 0;
}

void fileValidation (FILE * file) {

  if (file == NULL) {
    printf("Error Reading File\n");
    exit (0);
  }
}

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
