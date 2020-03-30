#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

// Declaring the Functions
// ----------------------------
void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void bubbleSort(long int n, long int a[]); // function that contains the bubble sort algorithm
void bubbleOP(long int n, long int a[]);// function that contains the bubble sort optmized algorithm

//------------------------------
int main(int argc, char const *argv[]) {
  //long int n = 100;
  //long int a[n];
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
    long int *a = (long int *) malloc(n*sizeof(long int)); // at this point I start to use malloc because in my work at school I have some problems with memory allocation
    printf("K = %d\n", k);
    // Comparingprintf("K = %d\n", k); the two algorithms
    random_array(n,a);
    printf("------------------BUBBLE SORT-------------\n");
    bubbleSort(n,a);

    random_array(n,a);
    printf("------------------OPTIMIZED BUBBLE SORT-------------\n");
    bubbleOP(n,a);
    free(a);// release the memory
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

void bubbleSort(long int n, long int a[]){
  long int i,j, aux;
  long int movementsCounter = 0; //variable to count the number of movements during the execution of the algorithm
  long int comparisonsCounter = 0;//variable to count the number of comparisons during the execution of the algorithm
  clock_t start,end; //variables to measure the time taken by the algorithm
  double timeUsed; // variable to store the value in seconds

  start = clock();
  for (i = n-1; i > 0; i--) {
    for ( j = 0; j < n; j++) {
      comparisonsCounter ++;// updating the value of the variable
      //comparing two adjacent elements
      if (a[j] > a[j+1]){ // condition to swap
        // if the element on the left is greater than the element on the right, they are not sorted and must be swapped
        aux =  a[j]; // auxiliar variable to swap the values inside the vector
        a[j] = a[j+1];
        a[j+1] = aux;
        movementsCounter += 3;//updating the value of the variable, for each swap we have 3 movements in the values of the array
      }
    }
  }
  end = clock();
  timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;

  printf("number of movements : %ld \n",movementsCounter );
  printf("number of comparisons : %ld \n",comparisonsCounter );
  printf("Time passed for sorting : %f \n", timeUsed );
}

void bubbleOP(long int n, long int a[]){
  long int i,j, aux;
  long int u; // this is the flag that will be used to mark the position where has happend the last exchange
  long int movementsCounter = 0; //variable to count the number of movements during the execution of the algorithm
  long int comparisonsCounter = 0;//variable to count the number of comparisons during the execution of the algorithm
  clock_t start,end; //variables to measure the time taken by the algorithm
  double timeUsed; // variable to store the value in seconds

  start = clock();
  j = n-1; // the last position is n-1 because the positions of tha array begins at zero
  while (j > 0) { // condition to stop the loop
    u = -1; //could be other value, since was less or equal to zero
    for (i = 0; i < j; i++) {
      comparisonsCounter ++; // updating the value of the variable
      //as in the original algorithm
      if (a[i] > a[i+1]) {
        aux = a[i];
        a[i] = a[i+1];
        a[i+1] = aux;
        u = i; //this update only happens when the if condition is satisfied, so it will mark the last exchange position
        movementsCounter += 3;//updating the value of the variable, for each swap we have 3 movements in the values of the array
      }
    }
    j = u; // in the next loop the array will be checked until the position marked in the variable u
  }
  end = clock();
  timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;

  printf("number of movements : %ld \n",movementsCounter );
  printf("number of comparisons : %ld \n",comparisonsCounter );
  printf("Time passed for sorting : %f \n", timeUsed );
}
