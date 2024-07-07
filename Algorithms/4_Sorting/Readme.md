# <b>Sorting</b>

![image](https://user-images.githubusercontent.com/103832825/218310565-e2d13365-d5e8-47e0-a95a-edb0b1119ba7.png)

## Table of Contents

* Introduction
* Sorting Algorithms
    * Selection Sort
    * Merge Sort
    * Count Sort
    * Quick Sort
    * Heap Sort
    * Comb Sort
* Conclusion

## Sorting Algorithms

Sorting algorithms are mainly of two types: comparison based and non-comparison based. It is proven mathematically that a comparison based sorting algorithm requires atleast O(nlon(n)).

### <b>1) Selection Sort</b>

Selection sort is a <b>comparison based sorting algorithm</b>.

In selection sort,we first find the minimum element in the given array. Then we swap the minimum element with the first element.We then repeat the above steps for remaining array.


### <b>2) Merge Sort</b>
Merge sort is a <b>comparison based sorting algorithm</b> based on <b>divide and conquer</b> technique.

In merge sort, we split the given array recursively and then sort them indivisually and merge them back.

### <b>3) Count Sort</b>
Count sort is a <b>Non-comparison based sorting algorithm</b> and has better time complexity than comparison based algorithms in general.

However, for this algorithm to work, we need to deal with a <b>fixed range</b> of integers only, say I know my input is a mix of integers in range 0-100, then count sort is appropriate. 

### <b>4) Quick Sort</b>
Quick sort is a <b>Comparison based sorting algorithm</b>. The runtime of this algorithm depends on the partitions which are created. If the partitions are always created at the center, the algorithm works in O(nlog(n)). However, if we were to assume the worst case, it would work in O(n^2). 

In Quick sort, we can prove that choosing a random element as a pivot is generally a good choice which increases our probability to get the partitions which lead to O(nlog(n)) time complexity. The same is depicted in ```randomized_quick_sort.cpp```.

### <b>5) Heap Sort</b>

In order to implement Heap sort, we can simply convert the given array into a <b>Max-Heap</b> and perform extract-max on it and place the maximum element so recieved at the end of array.

We can create a new priority queue and store elements in the new array one by one, maintaining the heap property. However this requires extra space. Thus, we can rather convert the given array into a priority queue itself, avoiding use of extra space. 

Heap sort works in O(nlog(n)) and is a comparison based algorithm.

### <b>6) Comb Sort</b>


ChatGPT
Comb Sort is like a smarter version of Bubble Sort. In Bubble Sort, we always check and swap neighboring elements. So, if a small number is at the end, it takes a long time to move to the front.

In Comb Sort, we introduce a gap between elements we compare. At first, this gap is quite large, which lets us compare elements that are far apart. After each pass through the list, we shrink this gap by a factor (usually 1.3). Eventually, the gap becomes 1, and Comb Sort behaves just like Bubble Sort, checking only adjacent elements. While Comb Sort is usually faster than Bubble Sort on average, worst case remains O(n^2).

## <b>Conclusion</b>

The time complexities of a few sorting algorithms are given below

![image](https://user-images.githubusercontent.com/103832825/218310768-d7d0b13e-bfe6-4f6b-a8fe-dd753132682a.png)

For visualization of the above sorting algorithms, refer : https://www.toptal.com/developers/sorting-algorithms and https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html.
