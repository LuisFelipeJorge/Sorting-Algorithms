#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

// Declaring the Functions
// ----------------------------
void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void selectionSort(long int n,long int a[]);// function that contains the sorting algorithm

int main(int argc, char const *argv[]) {
  int k; // we will test the two algorithms with more than one input
  long int n; // n is the size of the array
  for (k = 2; k <= 5; k++) { // k  will be the power to 10, and this will delimited our input to analise the two algorithms.
    //I did choose this range of test because in my previous work at the computer scienece classes
    //I realize that for values of k greater than 5 , the two algorithms needs very larges amounts of time to sort the array
    n = 1;
    int i = k;
    while (i > 0) {// loop to elevate the power of n,the size of the array
      n = 10*n;
      i--;
    }
    printf("K = %d\n", k);
    long int *array = (long int *) malloc(n*sizeof(long int));
    random_array(n,array);
    printf("------------------SELECTION SORT----------------------\n");
    //print_array(n,array);
    //testing the algorithm
    selectionSort(n,array);
    //print_array(n,array);
    free(array); // releasing space
  }
  getchar();
  return 0;
}

// Functions
//-----------------------------

void random_array(long int n, long int a[]){
  // n is the number of elements of the array
  srand(time(NULL));
  long int i;
  for (i = 0; i < n; i++) { // loop to fill the array
    a[i] = rand() % n;
    //this generates a set of random numbers in the range 0 to n
  }
}

void print_array(long int n, long int a[]){
  printf("Printing the array : \n" );
  long int i;
  int count = 0; // to count the number of columns in each row
  for ( i = 0; i < n; i++) {
    printf("a[%ld] = %ld ",i,a[i] );
    count += 1;
    if (count == 10){ // print the array in 10 columns
      printf("\n"); // new row
      count = 0; // return to count
    }
  }
}

void selectionSort(long int n,long int a[]){
  long int comparisonsCounter = 0;//variable to count the number of movements during the execution of the algorithm
  long int movementsCounter = 0;//variable to count the number of comparisons during the execution of the algorithm
  clock_t start,end; //variables to measure the time taken by the algorithm
  double timeUsed; // variable to store the value in seconds

  start = clock();
  long int i,j; // variables to auxiate the usage of the loops
  long int m; // variable to mark the position of the smallest elements (flag)
  long int tmp; // variable to auxiliate the swap

  for (i = 0; i < n-1; i++) {
    m = i;// this marks the  lefmost position of the unsorted array, or the boundary of the sorted array
    for (j = i+1; j < n; j++) {
        comparisonsCounter++;
        if (a[j] < a[m]){// finds the smalleste element of that turn in the loop
          // make the swap
          tmp = a[j];
          a[j] = a[m];
          a[m] = tmp;
          movementsCounter += 3;
        }
    }
  }
  end = clock();
  timeUsed = ((float)(end - start))/CLOCKS_PER_SEC;

  printf("number of movements : %ld \n",movementsCounter );
  printf("number of comparisons : %ld \n",comparisonsCounter );
  printf("Time passed for sorting : %f \n", timeUsed );
  }
