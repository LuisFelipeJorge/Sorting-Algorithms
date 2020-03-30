#include <stdio.h> // standard c library header
#include <stdlib.h>// c header file that contains functions as malloc, rand srand
#include <time.h> // c library for time functions

// Declaring the functions
//////////////////////////////////////////////////

void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]); // function to print the array in columns
long int key(long int x, int exp); // this function returns the rest of the division by 10, raised to the exponent "exp".
long int getMax(long int n, long int a[]);//this function returns the maximum value within an array
void countingSort(long int n, long int a[], int exp); // This function contains a stable sorting algorithm that will assist in the implementation of the radix sort.
void radixSort(long int n, long int a[]); // function that contains the sorting algorithm

 //////////////////////////////////////////////////

 int main(int argc, char const *argv[]) {
   int k; // represents the power of 10, and this will be the size of the array
   long int n;// n --> the size of the array
   clock_t start,end; // variables to measure the time passed to sort the array
   double timeUsed;

   for ( k = 2; k <= 8; k++) {

     n=1;
     int i = k;
     while (i > 0) {
       n = 10*n;
       i--;
     }
     long int *a =(long int *)malloc(n*sizeof(long int));
     if (a == NULL) {
       printf("Memory could not be allocated" );
       exit(EXIT_FAILURE); // in this case, we have a problem in the process of allocating memory for the array
     }else{
       random_array(n,a);
       printf("K = %d\n", k);
       printf("------------------------------RADIX SORT------------------------\n" );
       start = clock();
       radixSort(n,a);
       end = clock();

       timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;
       printf("Time passed for sorting : %f \n", timeUsed);

       free(a);
     }
   }

   getchar();
   return 0;
 }

 //////////////////////////////////////////////////

 void random_array(long int n, long int a[]){
   // n is the number of elements of the array
   srand(time(NULL));
   long int i;
   for (i = 0; i < n; i++) { // loop to fill the array
     a[i] = rand() % n;
     //this generates a set of random numbers in the range 0 to n
   }
 }

 //////////////////////////////////////////////////

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

 //////////////////////////////////////////////////

 long int key(long int x, int exp){
   return ((x/exp)%10); // the rest of the division by 10 raised to exp .
 }

 //////////////////////////////////////////////////

long int getMax(long int n, long int a[]){
  long int max = a[0];
  long int i;
  for(i = 0; i < n; i++){
    if (a[i] > max) { // finding out the maximum value
      max = a[i];// stores the maximum
    }
  }
  return max;
}

 //////////////////////////////////////////////////

 void countingSort(long int n, long int a[], int exp){
   long int i; // will auxiliate to make the loops
   int k = 10; // k -> represents the number of keys, as we are working with decimal numbers, we will work with 10 different types of keys {0 ... 9}
   long int count[k];
   // at this moment, the 'count' array will store in each index the number of elements of each key
   // as instance, count [0] will store the number of elements that have the key value equal to zero.
   for ( i = 0; i < k; i++) {
       count[i] = 0; //initializing the matrix with 0, to ensure that the algorithm does not access unwanted values
   }

   for ( i = 0; i < n; i++) {
     count[key(a[i],exp)] += 1;
     // storing the number of elements of each key values
     // example:
     // a[i] = 101 --> key(101,1) = 1 --> count[1] += 1
    }

    long int total = 0; //total is the range of elements for each type of key
    long int aux; // variable to auxiliate doing the swap
    for (i = 0; i < k; i++) {
      aux = count[i];
      count[i] = total;
      total += aux; // in each iteration, 'total' will store the index where the algorithm will start placing the values ​​for each key
    }
    // elements of key value zero starts at the index 0
    // elements of key value 1 starts at the index (0 + number of elements 0) and so on
    // count now contains the index of the position in which each type will be stored

    //auxiliar vector to help the sort process

    long int *b =(long int *)malloc(n*sizeof(long int));
    if (b == NULL) {
      printf("Memory could not be allocated" );
      exit(EXIT_FAILURE); // in this case, we have a problem in the process of allocating memory for the array
    }else{
      for ( i = 0; i < n; i++) {
        b[count[key(a[i],exp)]] = a[i];
        count[key(a[i],exp)] ++;
        // b receives the elements already placed according to their index
      }

      //overwriting b in a
      for (i =0 ; i < n; ++i){
        a[i]=b[i];
        }
      free(b);
    }
 }

 //////////////////////////////////////////////////

void radixSort(long int n, long int a[]){
  // Find the maximum number to know number of digits
  long int m = getMax(n,a);
  // Do counting sort for every digit. Note that instead
  // of passing digit number, exp is passed. exp is 10^i
  // where i is current digit number
  for (int exp = 1; m/exp > 0; exp *= 10){
      countingSort(n, a, exp);
    }
}

//////////////////////////////////////////////////
