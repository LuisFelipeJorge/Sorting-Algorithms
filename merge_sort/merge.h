void swapValues(long int *value1, long int *value2);
void createRandomArray(long int array[], long int arraySize);
void printArray(long int array[], long int arraySize);
void readArrayValues(long int array[], long int arraySize);
void mergeSortRecursive(long int array[],
  long int startIndex, 
  long int endIndex, 
  long int *numberOfComparisons, 
  long int *numberOfExchanges);
void merge(long int array[], 
  long int leftStartIndex, 
  long int leftEndIndex, 
  long int rightStartIndex, 
  long int rightEndIndex, 
  long int *numberOfComparisons, 
  long int *numberOfExchanges);