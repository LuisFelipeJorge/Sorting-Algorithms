#include <stdio.h>
#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

// Declaring the Functions
/////////////////////////////////////////////////
void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void mergeSort(long int n, long int a[]);//function that contains the sorting algorithm
//void merge(long int n,long int a[]);

int main(int argc, char const *argv[]) {
  int k; // we will test the two algorithms with more than one input
  long int n; // n is the size of the array
  for (k = 2; k <= 8; k++) { // k  will be the power to 10, and this will delimited our input to analise the two algorithms.
    //I did choose this range of test because in my previous work at the computer scienece classes
    // I realize that for values of k greater than 5 , the n² algorithms needs very larges amounts of time to sort the array
    // But for merge, this limit can be exceeded

    n = 1;
    int i = k;
    while (i > 0) {// loop to elevate the power of n,the size of the array
      n = 10*n;
      i--;
    }
    long int *a = (long int *) malloc(n*sizeof(long int)); // allocating the space
    random_array(n,a);
    //print_array(n,a);
    printf("K = %d",k);
    printf("--------------------MERGE SORT-----------------------\n");
    mergeSort(n,a);
    free(a);
    //print_array(n,a);
  }
  getchar();
  return 0;
}


// Functions
///////////////////////////////////////////////

void random_array(long int n, long int a[]){
  // n is the number of elements of the array
  srand(time(NULL));
  long int i;
  for (i = 0; i < n; i++) { // loop to fill the array
    a[i] = rand() % n;
    //this generates a set of random numbers in the range 0 to n
  }
}

/////////////////////////////////////////////////

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

/////////////////////////////////////////////////
void mergeSort(long int n, long int a[]){
  long int movementsCounter = 0; //variable to count the number of movements during the execution of the algorithm
  long int comparisonsCounter = 0;//variable to count the number of comparisons during the execution of the algorithm
  clock_t start,end; //variables to measure the time taken by the algorithm
  double timeUsed; // variable to store the value in seconds

  ////////////////////////////////////////////////
  // starting the algorithm
  start = clock();

  long int *auxiliary = (long int*) malloc(n*sizeof(long int)); // auxiliary array to help place elements within the input array
  long int s; // variable that represents the block size of the array that the algorithm will merge.
  for (s = 1; s < n; s*=2) {
    // Each iterarion of this loops double the size block
    // It is this multiplication factor that attributes the logarithmic function to the time complexity of the algorithm
    long int p = 0; //variable representing the position in the auxiliary array where the elements will be placed during the merging process
    while (p < n ) { // assuring that the algorithm stay inside the array
      // this 'while loop' will occur n times, thus the time complexity is the product of these 2 loops, n from the 'while loop' and log(n) from the previous 'for loop'
      long int beg1 = p;  // variable that represents the beginning of the first block in the merge process
      long int beg2 = p + s;  // variable that represents the beginning of the second block in the merge process, is equal beg1 plus the block size
      long int end1 = beg1 + s; // variable that represents the ending of the first block in the merge process
      long int end2 = beg2 + s; //variable that represents the ending of the second block in the merge process, is equal end1 plus the block size

      if(end1 > n ){ // The size of the variables will never exceed the size of the array
        end1 = n;
      }if(end2 > n ){
        end2 = n;
      }
      comparisonsCounter += 2;
      // Starting the merge process
      while (beg1 < end1 && beg2 < end2 ) {
        // checking if the two blocks have not finished yet
        comparisonsCounter++;
        if (a[beg1] <= a[beg2]){
          // placing the smallest elements of the two blocks first
          auxiliary[p] = a[beg1];// when the smallest element is in the first block
          movementsCounter++;
          // Updating the position variable and the address inside the array
          p++;
          beg1++;
        }else {
          auxiliary[p] = a[beg2];// when the smalleste element is in the second block
          movementsCounter++;
          // Updating the position variable and the address inside the array
          p++;
          beg2++;
        }
      }
      // at this moment in the algorithm, one of the two block has finished
      // So we need to check which one has not ended and then copy it into the auxiliary array
      // We only need to copy because we are able to assume that this portion was sorted in previous steps
      while (beg1 < end1) {
        // in the case the first block had not ended
        auxiliary[p] = a[beg1];
        movementsCounter++;
        p++;
        beg1++;
      }
      while (beg2 < end2) {
        // in the case the second block had not ended
        auxiliary[p] = a[beg2];
        movementsCounter++;
        p++;
        beg2++;
      }

    }
    long int i;
    // copying the auxiliary array in the input array
    for (i = 0; i < n; i++){
      a[i] = auxiliary[i];
    }
  }
  free(auxiliary); // releasing the memory

  ////////////////////////////////////////////////
  // ending of the algorithm
  end = clock();
  timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;

  printf("number of movements : %ld \n",movementsCounter );
  printf("number of comparisons : %ld \n",comparisonsCounter );
  printf("Time passed for sorting : %f \n", timeUsed );
}
