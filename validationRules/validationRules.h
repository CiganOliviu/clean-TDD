#include "../dependencies/libraries.h"
#include "../dependencies/dataStructures.h"

typedef struct validationRules {

  int (*isNegative)(int * number);
  int (*isZero)(int * number);
  void (*fileValidation)(FILE * file);

} validationRules;

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
