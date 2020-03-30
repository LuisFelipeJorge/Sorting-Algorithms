#include <stdio.h>
#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

// Declaring the Functions
/////////////////////////////////////////////////
void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void mergeSR(long int l,long int r, long int a[]);// function that contais the algorithm merge sort
void merge(long int l, long int m, long int r, long int a[]);// function to merge the parts of the array

/////////////////////////////////////////////////

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
    long int *a = (long int *) malloc(n*sizeof(long int));
    random_array(n,a);
    printf("K = %d\n", k );
    printf("----------------------RECURSIVE MERGE SORT --------------------------\n" );
    clock_t start, end;
    double timeUsed;
    start = clock();
    mergeSR(0,n,a);
    end = clock();
    timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Time passed for sorting : %f \n", timeUsed);
    free(a);
  }

  getchar();
  return 0;
}

/////////////////////////////////////////////////

//FUNCTIONS

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

void mergeSR(long int l,long int r, long int a[]) {
  // Recursive version of MERGE SORT
  //l --> left block boundary
  //r --> right block boundary
  if (l < r) {
    //make sure that the smallest block size will be of size 1
    long int m = (long int)(r + l)/2;// m --> mean of the list of numbers

    // using recursion :
    mergeSR(l,m,a);   // calling the function for the first half of the print
    mergeSR(m+1,r,a);// calling the function for the second half of the print
    merge(l,m,r,a); // function to merge the two halves
  }

}

/////////////////////////////////////////////////

void merge(long int l, long int m, long int r, long int a[]) {
  long int i,j,k;
  long int n1 = m - l + 1; // n1 is representing the first block size
  long int n2 = r - m; // n1 is representing the second block size

  // Creating auxiliary arrays to place the elements
    long int *lhalf = (long int *) malloc(n1*sizeof(long int)); // left half
    long int *rhalf = (long int *) malloc(n2*sizeof(long int));// right half

    // filling the auxiliary arrays with the elements of the corresponding portion of the input array
    for (i = 0; i < n1; i++) {
      lhalf[i] = a[l + i];
    }
    for (j = 0; j < n2; j++) {
      rhalf[j] = a[m + 1 + j];
    }

    // Starting the merge process
    long int beg1 = 0;// variable that represents the beginning of the first block in the merge process
    long int beg2 = 0;// variable that represents the beginning of the second block in the merge process
    long int p = l; // the position to place the elements
    while (beg1 < n1 && beg2 < n2) {// checking if the two blocks have not finished yet
    // placing the smallest elements of the two blocks first
      if (lhalf[beg1] <= rhalf[beg2]) {
        a[p] = lhalf[beg1];// when the smallest element is in the first block
        //Updating the position variable and the address inside the array
        beg1++;
        p++;
      }else{
        a[p] = rhalf[beg2];// when the smallest element is in the second block
        //Updating the position variable and the address inside the array
        beg2++;
        p++;
      }
    }
    // at this moment in the algorithm, one of the two block has finished
    // So we need to check which one has not ended and then copy it into the auxiliary array
    // We only need to copy because we are able to assume that this portion was sorted in previous steps
    while (beg1 < n1) {
      // in the case the first block had not ended
      a[p] = lhalf[beg1];
      beg1++;
      p++;
    }
    while (beg2 < n2) {
      a[p] = rhalf[beg2];
      beg2++;
      p++;
    }
    free(lhalf);
    free(rhalf);
}
