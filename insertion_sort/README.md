# Insertion Sort

Insertion-Sort is an  in-place comparison-based sorting algorithm as Bubble-Sort.As we saw in the selection sort algorithm, insertion assumes that a part of the array is sorted, and then you need to add, "to insert," a new element into the sorted sublist of numbers. The algorithm works by comparing adjacent elements, when it finds a pair that is not sorted, makes a switch and begins checking the element exchanged with the other elements to the left of the original position and continues to do so until it finds the correct position of the number.

We can see in the final version of the code that the insertion sort algorithm has a better performance when it's compared with bubble or selection.Computationally, this algorithm needs to perform fewer steps to sort the list of numbers it receives as input. Nevertheless, as we can see from the code, this algorithm runs two loops of size n to sort the array, so as the others that were mentioned insertion sort have time complexity
**O(n²)** and space complexity **O(1)**.
