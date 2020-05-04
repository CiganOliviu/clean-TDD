#include "../dependencies/libraries.h"
#include "../dependencies/dataStructures.h"

typedef struct validationRules {

  int (*isNegative)(int * number);
  int (*isZero)(int * number);
  void (*fileValidation)(FILE * file);

} validationRules;

int isNegative (int * number);
int isZero (int * number);
void fileValidation (FILE * file);

typedef struct errorsHandler {

  int (*oneDimensionalArrayErrorsHandler)(oneDimensionalArrayType oneDimensionalArray);

} errorsHandler;

int oneDimensionalArrayErrorsHandler (oneDimensionalArrayType oneDimensionalArray);
