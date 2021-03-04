# Insertion Sort

Insertion-Sort is an  in-place comparison-based sorting algorithm as Bubble-Sort. As we saw in the selection sort algorithm, insertion assumes that a part of the array is sorted, and then you need to add, "to insert," a new element into the sorted sublist of numbers. The algorithm works by comparing adjacent elements, when it finds a pair that is not sorted, makes a swap and begins checking the element exchanged with the other elements to the left of the original position and continues to do so until it finds the correct position of the new element.
Insertion is the simplest algorithm to be implemented, regardless to the code, we only need a few lines to build its logic. In its worst scenario (a reverse ordered array), the algorithm would have to go through each element i-1 times, where i represents the index of the element's position. This index would grow to the limit n-1 (entry size).

Analyzing it as the sum of an arithmetic progression:

> 1 + 2 + 3 + ... + n-2 + n-1

We see that the result has a quadratic term, which also represents the number of movements performed by the algorithm.

Insertion's time complexity is **O(n2)** and, as it uses no extra memory, **O(1)**.

We can see in the tests that the insertion sort algorithm has a better performance when it's compared with bubble or selection.