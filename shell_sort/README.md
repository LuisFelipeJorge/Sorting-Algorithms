# Shell Sort

The Shell Sort has the same behavior as the insertion sort algorithm, it is also a *in-place comparison algorithm*, but different from the insertion, it starts by sorting the pair of numbers that are far apart, we can call this distance as *"gap"*. After that, the program starts to gradually decrease the value of the interval between the elements to be compared. When the algorithm reaches a gap value of 1, it becomes a version of the insertion sort algorithm.

Therefore, as we already know the insertion, we can be sure that, in the end, the input array will be classified, the difference between these two programs is the sequence of intervals, depending on the way it is implemented, we are able to reduce the time complexity of the algorithm. This is because in previous passages, with higher gap values, the *ShellSort* algorithm is transforming the input array into an almost sorted aray, and this is the best case scenario for insertion. Experimentally, [Ciuria, Marcin (2001)](http://sun.aei.polsl.pl/~mciura/publikacje/shellsort.pdf) found the best sequence for the algorithm: 

> **{701,301,132,57,23,10,4,1}**

With this sequence the shell sort can give us the best performance among the quadratic algorithms and have an output comparable to the logarithmic algorithms for smaller inputs (**10⁴**).
