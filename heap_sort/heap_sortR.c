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
void print_array(long int n, long int a[]); // function to print the array in columns
void heapfy(long int p, long int m, long int a[]); // function to create a heap data structure inside the input array
void heapSortR(long int n, long int a[]);//function that contains the sorting algorithm
void swap(long int *x, long int *y);//function to swap the values ​​of two variables, passing the pointers of each variable as arguments


//////////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {

  int k; // represents the power of 10, and this will be the size of the array
  long int n;// n --> the size of the array
  for(k = 2; k <= 8; k++){
    n = 1;
    int i = k;
    while (i > 0) {
      n = n*10;
      i--;
    }
    long int *a = (long int *) malloc(n*sizeof(long int));
    if (a == NULL) {
      printf("Memory could not be allocated" );
      exit(EXIT_FAILURE); // in this case, we have a problem in the process of allocating memory for the array
    }else{
      clock_t start,end; // variables to measure the time passed to sort the array
      double timeUsed;

      random_array(n,a);
      printf("K = %d\n",k );
      printf("------------------------RECURSIVE HEAPSORT -----------------\n" );

      start = clock();
      heapSortR(n,a);
      end = clock();

      timeUsed = ((double)(end - start))/CLOCKS_PER_SEC;

      // Analysing the output of the algorithm
      printf("number of movements : %ld \n",movementsCounter );
      printf("number of comparisons : %ld \n",comparisonsCounter );
      printf("Time passed for sorting : %f \n", timeUsed);

      free(a);// releasing the memory allocated
    }
  }
  getchar();
  return 0;
}
//////////////////////////////////////////////////////////

//Functions
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

void heapfy(long int p, long int m, long int a[]) {
  // p --> represents the index of the parent node (root) of the binary tree that the function receive as input
  // m --> represents the number of the nodes of the binary tree  that the function receive as input
  // a[] --> the input print_array
  long int f = 2*p +1; // f --> represents the index of one of the child nodes(we will assume it is the left child)
  // (2*p + 2) for example is the index of the other child node (right child)

  if (f < m) { // This condition ensures that the last child index is within the range of the array
    //this means that the algorithm will not have access to a position that does not belong to the array.
    comparisonsCounter++;

    if ((f + 1) < m ) {// note that (f + 1) = (2*p + 2), therefore , (f+1) represents the index of another child node
      // this condition also ensures that the last child index is within the range of the array
      comparisonsCounter++;

      if (a[f+1] > a[f]) {
        //in the case the right child key is greater than the left child key
        // we will use the index of the greater child key as reference
        comparisonsCounter++;
        f++;
      }
    }
      if (a[p] < a[f]) {
        // in the case the child node key is greater than the parent node key, to mantain the heap data structure
        //we need to swap the parent key for the greater key between your two children, as previously stated, f is the reference for the greater child key.
        comparisonsCounter++;
        swap(&a[p],&a[f]);
        movementsCounter += 3;// number of movements inside the array during the swap function

        heapfy(f,m,a);// calling recursively the function to ensure that after exchange the values of the nodes, we keep the heap structure inside the input array
      }
    }
}

//////////////////////////////////////////////////////////

void heapSortR(long int n, long int a[]) {
  long int end; // variable to represent the ending of the array, the last position

  for (end = n-1; end >= 0; end--) {
    heapfy(end,n,a);
    // With this 'for loop' the algorithm will transform the input array in a heap data structure
    //This means that the elements of the array will be seen as a binary tree, inside which for each node C we will see a parent node P with a key value greater than
    // or equal to the key value of C.
    // the first element, array[0], is the root of this tree, and as we are working with a binary tree, we also know that array[0] have th greater key value of all the nodes
  }

  for(end = n-1; end >= 0; end--){
    swap(&a[0],&a[end]);// with this, at each loop, we are placing the greater elements of our set of numbers in the rightmost positions of the array
    // when the variable 'end' is updated, the algorithm is cutting of the rightmost node of the binary tree
    movementsCounter += 3;
    heapfy(0,end,a); // calling recursively the function to ensure that after exchange the values of the nodes, we keep the heap structure inside the input array
  }
}

//////////////////////////////////////////////////////////
