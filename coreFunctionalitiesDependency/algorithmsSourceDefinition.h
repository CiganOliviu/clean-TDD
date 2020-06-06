typedef struct divideEtEmperaAlgorithms {

  int (*linearBinarySearch)(oneDimensionalArrayType oneDimensionalArray, int valueToSearch);
  int (*maxDivideEtEmpera)(oneDimensionalArrayType oneDimensionalArray, limits interval);
  int (*minDivideEtEmpera)(oneDimensionalArrayType oneDimensionalArray, limits interval);

} divideEtEmperaAlgorithms;

int linearBinarySearch (oneDimensionalArrayType oneDimensionalArray, int valueToSearch);
int maxDivideEtEmpera (oneDimensionalArrayType oneDimensionalArray, limits interval);
int minDivideEtEmpera (oneDimensionalArrayType oneDimensionalArray, limits interval);
