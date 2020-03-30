#include <stdio.h>  // standard header for c language
#include <stdlib.h> // header file that contains the rand and srand function
#include <time.h> //library that contains the time function

//Global variables  to count the number of movements and comparisons that occurs inside the algorithm
//////////////////////////////////////////////////////////

// As this variables are used in more than one function, we need them to belong to the higher skope of the program
long int movementsCounter = 0;
long int comparisonsCounter = 0;

//////////////////////////////////////////////////////////

//Declaring the Functions
//////////////////////////////////////////////////////////

void random_array(long int n, long int a[]); // fuction to generate random numbers in an array
long int random_number(long int low, long int upp); // function that returns a random number that belongs to the range (lower,upper)
void print_array(long int n, long int a[]); // function to print the array in columns
void swap(long int *x, long int *y);//function to swap the values ​​of two variables, passing the pointers of each variable as arguments
void quickSort(long int beg, long int end, long int a[]);//function that contains the sorting algorithm
int cmpfunc(const void * a, const void * b); // function to auxiliate the qsort function, standard c library for the quick sort algorithm


//////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {

  int k; // represents the power of 10, and this will be the size of the array
  long int n;// n --> the size of the array
  clock_t t_start1,t_start2,t_end1,t_end2; // variables to measure the time passed to sort the array
  double timeUsed;
  for(k = 2; k <= 8; k++){
    n = 1;
    int i = k;
    while (i > 0) {
      n = 10*n;
      i--;
    }
    long int *a = (long int *)malloc(n*sizeof(long int));
    if (a == NULL) {
      printf("Memory could not be allocated" );
      exit(EXIT_FAILURE); // in this case, we have a problem in the process of allocating memory for the array
    }else{
      printf("K = %d\n", k );
      random_array(n,a);

      t_start1 = clock();
      quickSort(0,n,a);
      t_end1 = clock();

      timeUsed = ((double)(t_end1 - t_start1))/CLOCKS_PER_SEC;
      printf("-----------------------QUICK SORT------------------\n");
      //Analysing the output of the algorithm
      printf("number of movements : %ld \n",movementsCounter );
      printf("number of comparisons : %ld \n",comparisonsCounter );
      printf("Time passed for sorting : %f \n", timeUsed);

      //Comparing the implementation with the C standard function
      // void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
      // base − This is the pointer to the first element of the array to be sorted.
      // nitems − This is the number of elements in the array pointed by base.
      // size − This is the size in bytes of each element in the array.
      // compar − This is the function that compares two elements.
      // Source --> tutorials point
      random_array(n,a);
      t_start2 = clock();
      qsort(a,n,sizeof(long int),cmpfunc);
      t_end2 = clock();
      printf("-----------------------QSORT------------------\n");
      timeUsed = ((double)(t_end2 - t_start2))/CLOCKS_PER_SEC;
      printf("Time passed for sorting : %f \n", timeUsed);

      free(a);
    }
  }

  getchar();
  return 0;
}

//////////////////////////////////////////////////////////

//FUNCTIONS
//////////////////////////////////////////////////////////

void random_array(long int n, long int a[]){
  // n is the number of elements of the array
  srand(time(NULL));
  long int i;
  for (i = 0; i < n; i++) { // loop to fill the array
    a[i] = rand() % n;
    //this generates a set of random numbers in the range 0 to n
  }
}

//////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////

void swap(long int *x, long int *y) {
  long int tmp;// tmp --> temporary variable to help to exchange the pointers of the variables passed as input
  tmp = *x;
  *x = *y;
  *y = tmp;
}

//////////////////////////////////////////////////////////

long int random_number(long int low, long int upp) {
  srand(time(NULL));
  return ((rand() % (upp - low + 1) ) + low);
}

//////////////////////////////////////////////////////////

void quickSort(long int beg, long int end, long int a[]) {
  long int p; // p --> represents the pivot index
  long int l,r;
  // l --> 'left' variable that the algorithm will use as a reference to evaluate the block elements (beginning, end), starting at the leftmost position after the pivot
  // r --> 'right' variable that the algorithm will use as a reference to evaluate the block elements (beginning, end), starting at the rightmost position
  long int pivot; // will cary the pivot element

  if (beg < end) {
    // With this statement we are verifying if there is the necessity to call the algorithm
    // Since we’re going to use the recursive approach, we need to check where the calls really should lead to an implementation and where we can avoid steps
    // In the case the function receives as input an interval that dosen't have an phisical interpretation, as an array of a negative size:
    // (end - beg < 0) => beg > end, the algorithm will just avoid all the steps and will do nothing
    comparisonsCounter++;

    p = random_number(beg,end); // choosing randomly the position of the pivot
    // with this approach, we try to hinder the chances that the algorithm can receive its worst case scenario, where we have bad choices for the pivot
    //An example of a bad pivot is the elements of the extremities
    pivot = a[p];
    swap(&a[p],&a[beg]); // placing the pivot element at the beginning of the block were the algorithm is working on
    movementsCounter += 3;// number of movements inside the array during the swap function
    l = beg + 1; // will help to find elements smaller than the pivot and therefore will be placed to the left of its position
    r = end; //will help to find elements greater than the pivot and therefore will be placed to the right of its position

    while (l <= r) {
      // In the case l > r, the algorithm will start to check twice the same position
      comparisonsCounter++;
      while (l <= r && a[l] <= pivot) {
        l++; // walking to the right -->
        comparisonsCounter++;
      }
      while (l <= r && a[r] >= pivot) {
        r--;// walking to the left <--
        comparisonsCounter++;
      }
      if(l < r){
        // at this moment, if the above condition was satisfied, this means that we find and element that is greater than the pivot on its left
        // and also and element that is smaller on its right, so we need to exchange this two
        comparisonsCounter++;
        swap(&a[l],&a[r]);
        movementsCounter += 3;
      }
    }
    // after the 'while' loop we will place the pivot on the right position
    // r will hve the index of the last element that is smaller than the pivot
    swap(&a[beg],&a[r]);
    movementsCounter += 3;

    //recursion
    quickSort(beg, r-1, a); // calling the function for the block on the left of the pivot
    quickSort(r+1, end, a); // calling the function for the block on the right of the pivot
  }
}

//////////////////////////////////////////////////////////

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

//////////////////////////////////////////////////////////
