# Selection Sort

This algorithm works with the idea of ​​sorting a stack of paper. Let's find the smallest element within our number set and then place that number in the correct position inside the array. Another way to understand its behavior is to think that the algorithm assumes that the array is divided into two parts, one that is already sorted and the other not. At first, the sorted part is emptied and the unclassified is the entire list of numbers. The algorithm finds the smallest element and then exchanges it for the leftmost element of the unsorted array; therefore, the sorted part begins to grow, the exchanged element becomes part of the sorted array. This process is repeated element by element, moving the boundary of the sorted array, until the unclassified part is emptied.

By analyzing the behavior of the selection sort algorithm, we can see that they have a better result compared to the first version of the bubble sort algorithm. The selection algorithm makes fewer moves and comparisons while sorting the array. We can see the difference in larger inputs, arrays with more than 10,000 elements.

regardless of the statement, this algorithm, as the two versions of the bubble sort, is also an algorithm with time complexity **O(n²)** and memory complexity **O(1)**.
