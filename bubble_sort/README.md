# Bubble Sort Algorithm
  I believe this is the simplest and easiest sorting algorithm to learn, in my
Computer Science classes it was the first algorithm presented to the students.

  This algorithm works by comparing two adjacent elements.
To understand the logic of the code:
- Take the first two elements of a vector, we will use an integer vector to simplify understanding. We want to sort up, so imagine the vector as a list of random numbers; If the left element of the vector has a value less than the right element (remember that we are comparing two at a time), do nothing. Otherwise, it means that the left element is bigger than the right element, change them.
- Keep doing this until the end of the vector, two adjacent elements at a time.
- Repeat this action n times to assure the array will be sorted.


  If the vector has **n** elements, to ensure that the vector is sorted, we will
repeat this process **nxn** times. I know we don't have to go that far, but for the first time, let's keep going like this.
  The time complexity of this algorithm is **O(n²)**, where n represents the size
of the vector we want to order. Memory complexity is **O(1)**, because the number of variables we use within the code is independent of the input size and it is always constant.

## Bubble Sort Optimized Algorithm

Something we can see that happens in the bubble algorithm, each time it goes through the array, it places the largest element at the end of the array.
We could face a scenario where, at some point in the array, the elements are already sorted, so the algorithm does not really need to check this part of the array again. If we could say where this happens, we could avoid unnecessary actions and make the algorithm more efficient in terms of the number of operations performed.

Actually, we can do that, remember that the algorithm only swaps two adjacent elements when they are not sorted, so if it passes through the array and no longer sees changes, that part of the array is ​​already sorted. Therefore, we only need to somehow mark the position of the array at which the last exchange occurs, after which we prevent the algorithm from going beyond that position.

To make it easier to visualize the difference between the two algorithms we will create two auxiliary variables to count the number of comparisons that occur while it sorts the array and also the number of moviments that the algorithm has made, for instance when it needs to swap two elements.

But something important to note is that the changes we made to optimize the algorithm did not change its complexity, either in memory or in time. The behavior of the algorithm with respect to the time required to sort continues with a **O(n²)**.
