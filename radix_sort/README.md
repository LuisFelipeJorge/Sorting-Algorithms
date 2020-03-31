# RADIX SORT ALGORITHM  

Radix Sort is a fast and stable sorting algorithm, radix is also a non-comparative algorithm, it avoids comparisons by creating and distributing the elements to be sorted in keys.  

Radix was first developed to be implemented as a mechanical algorithm to classify punched cards. It has been adapted to a computational approach in a way that can be applied to different types of data, more specifically lexicographically ordered data, as words, as integers and more.

In our example, we worked with integers to make it easier to understand the logic behind the algorithm. When working with numbers, we could take two approaches to do the sorting processes, to sort by the most significant digit (MSD) or the least significant digit (LSD). As I chose the latter, I will explain it and I believe that we could export the same thought to the other . 

As we are working with integers, in our context, we have 10 keys to use, which are: [0, 1, 2, ..., 8, 9]. In the code, I implemented the function *countingSort*, responsible for sorting the elements by their key values, placing the short keys first and the longest keys later. The function receives as parameters the input array, its size and exp, which represents an exponent. This exponent helps us to know in which digit we are sorting.

For example, our algorithm receive as input the following array:

> [94, 16, 12, 56, 96, 17, 69]

First, we find the biggest element to know the possible values ​​of exp; in this example, the largest number is 96; therefore, exp will be 0 and 1, so we will work with 2 digits, the unit and the ten. First we sort the element by its LSD and we have.

> [12, 94, 16, 56, 96, 17, 69]

After that we raise the value of exp and the apply the *countingSort* to the next digit, the final result is sorted:

> [12, 16, 17, 56, 69, 94, 96]

The radix sort can be summarized as successive implementations of *countingSort*. Just to make an observation, we do not necessarily need to use the *countingSort* in the process, for example, we could have used the *bubble sort*, the *merge sort* or any other that satisfies the condition of **stability** ([GeeksforGeeks](https://www.geeksforgeeks.org/stability-in-sorting-algorithms/)).