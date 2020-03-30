#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

////Global variables  to count the number of movements and comparisons that occurs inside the algorithm
/////////////////////////////////////////////////////////

long int movementsCounter = 0;
long int comparisonsCounter = 0;

/////////////////////////////////////////////////////////


//Declaring the Functions
/////////////////////////////////////////////////////////

void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
void print_array(long int n, long int a[]);// function to print the array in columns
void shellSort(long int n, long int a[]); // function that contains the sorting algorithm

/////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {

  int k; // represents the power of 10, and this will be the size of the array
  long int n;// n --> the size of the array
  for(k = 2; k <= 6; k++){
    n = 1;
    int i = k;
    while (i > 0) {
      n = n*10;
      i--;
    }
    long int *a = (long int *) malloc(n*sizeof(long int));if (a == NULL) {
      printf("Memory could not be allocated" );
      exit(EXIT_FAILURE); // in this case, we have a problem in the process of allocating memory for the array
    }else{
      clock_t start,end; // variables to measure the time passed to sort the array
      double timeUsed;

      random_array(n,a);
      printf("K = %d\n",k );
      printf("------------------------SHELL SORT-----------------\n" );
      start = clock();
      shellSort(n,a);
      end = clock();
      timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;

      // Analysing the output of the algorithm
      printf("number of movements : %ld \n",movementsCounter );
      printf("number of comparisons : %ld \n",comparisonsCounter );
      printf("Time passed for sorting : %f \n", timeUsed);
      free(a);// releasing the memory
    }
  }

  getchar();
  return 0;
}

/////////////////////////////////////////////////////////

void random_array(long int n, long int a[]) {
  // n is the number of elements of the array
  srand(time(NULL));
  long int i;
  for (i = 0; i < n; i++) { // loop to fill the array
    a[i] = rand() % n;
    //this generates a set of random numbers in the range 0 to n
  }
}

/////////////////////////////////////////////////////////

void print_array(long int n, long int a[]) {
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

/////////////////////////////////////////////////////////

void shellSort(long int n, long int a[]) {
  // This algorithm is pretty similar with the insertion sort algorithm
  // the major difference is that in this case we will implement a gap system
  // this system will transform the array in the best case scenario for the insertion, an array almost sorted
  // at the end the algorithm will implement the insertion, but the gap system will help to decrease its time complexety
  // we will use the best sequence tested for the gap,
  // gaps = {701,301,132,57,23,10,4,1} - Ciura, Marcin (2001)

  long int gaps[8] = {701,301,132,57,23,10,4,1};
  long int  g; // g --> store the gap value
  long int cont,i,j; // variables to auxiliate the loops
  long int m; //m --> stores the value that will be 'inserted' in the array, according to the insertion sort algorithm
  for (cont = 0; cont <= 7; cont++ ){
    g = gaps[cont];

    // Now the we will see the same implemantation of the insertion sort algorithm
    for( i = 0; i <= n-g; i++ ){
      m = a[i + g];
      movementsCounter++;
      j = i;
      while (j >= 0 && a[j] > m) {
        comparisonsCounter++;
        a[j + g] = a[j];
        movementsCounter++;
        j -= g;
      }
      a[j + g] = m;//placing the element in the right position
      movementsCounter++;
    }
    // we are able to see that the final value og g will be 1, at this moment sheel sort will become the insertion sort, therefore the array will be sorted anyway
    // using these gap sequence we transform the array in an almost sorted input, and then the algorithm fall into the best case scenario for the insertion sort
    // is this features that decrease the time complexety of the algorithm
  }
}
