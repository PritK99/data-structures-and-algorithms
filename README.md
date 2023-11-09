# The Data Structures and Algorithm Saga 

## Introduction
A data structure is a data organization, management, and storage format that is usually chosen for efficient access to data. In simple words, data structures are just a way to represent data in memory which makes storing, operating on them etc very efficient.

<img src = "https://i.ytimg.com/vi/Qmt0QwzEmh0/maxresdefault.jpg" alt = "Images of Data structure">

## File Structure
```
data-structures-and-algorithms/
├── 01_Arrays
│   ├── dynamic_array.c
│   └── README.md
├── 02_Stack
│   ├── minimum_element.cpp
│   ├── Miscellaneous
│   │   ├── Balancing_brackets.cpp
│   │   └── README.md
│   ├── README.md
│   └── stack.cpp
├── 03_Queues
│   ├── Miscellaneous
│   │   ├── Queue_using_2_stacks.cpp
│   │   └── readme.md
│   ├── Queue_using_arrays
│   │   ├── circular_queue.cpp
│   │   ├── Queue_using_one_pointer.cpp
│   │   ├── Queue_using_two_pointer.cpp
│   │   └── readme.md
│   ├── Queue_using_Linked_list
│   │   ├── readme.md
│   │   └── simple_queue.cpp
│   └── readme.md
├── 04_Linked List
│   ├── linked_list.cpp
│   └── readme.md
├── 05_Trees
│   ├── avl.cpp
│   ├── binary_search_tree.cpp
│   ├── README.md
│   ├── tree_traversal.cpp
│   └── tree_traversal_iterative.cpp
├── 06_Priority_Queues_and_Heaps
│   ├── max_heap.cpp
│   └── README.md
├── 07_Disjoint_Sets
│   ├── disjoint_sets_using_arrays.cpp
│   └── README.md
├── 08_Hashing
│   ├── hashmap.c
│   └── README.md
├── 09_Graphs
│   ├── adj_list.cpp
│   ├── adj_matrix.cpp
│   ├── bfs.cpp
│   ├── dag.cpp
│   ├── dfs.cpp
│   ├── kruskals.cpp
│   ├── README.md
│   └── topological_sort.cpp
├── 8_Hashing
│   ├── integer_hashmap.c
│   └── naive_hashmap.c
├── Algorithms
│   ├── 0_Recursion
│   │   ├── pallindrome.cpp
│   │   ├── README.md
│   │   └── tower_of_hanoi.cpp
│   ├── 1_Greedy_Algorithms
│   │   ├── huffman.cpp
│   │   └── Readme.md
│   ├── 2_Divide_and_Conquer
│   │   ├── counting_inversions.cpp
│   │   ├── polynomial_multiplication_karatsuba.cpp
│   │   ├── polynomial_multiplication_naive.cpp
│   │   └── Readme.md
│   ├── 3_Dynamic_Programming
│   │   ├── coin_change.cpp
│   │   ├── knapsack_limited.cpp
│   │   ├── longest_common_sequence.cpp
│   │   ├── optimal_alignment.cpp
│   │   ├── placing_parentheses.cpp
│   │   ├── Readme.md
│   │   └── Sliding Window
│   │       └── README.md
│   ├── 4_Sorting
│   │   ├── count_sort.cpp
│   │   ├── heap_sort.cpp
│   │   ├── merge_sort.cpp
│   │   ├── quick_sort.cpp
│   │   ├── randomized_quick_sort.cpp
│   │   ├── Readme.md
│   │   └── selection_sort.cpp
│   └── 5_Miscellaneous
│       ├── fibonacci.cpp
│       ├── kadanes.cpp
│       ├── ministry.c
│       └── README.md
├── assets
│   ├── aggregate_amortized.png
│   ├── amortized_analysis.png
│   ├── bankers_amortized.png
│   ├── heap_example.png
│   ├── heap_properties.png
│   ├── output_10_0.png
│   ├── output_12_0.png
│   ├── output_15_0.png
│   ├── output_18_0.png
│   ├── output_20_0.png
│   ├── output_22_0.png
│   ├── output_24_0.png
│   ├── output_26_0.png
│   ├── output_28_0.png
│   ├── output_30_0.png
│   ├── output_32_0.png
│   ├── output_34_0.png
│   ├── output_36_0.png
│   ├── output_38_0.png
│   ├── output_5_0.png
│   ├── output_7_0.png
│   ├── physicist_amortized_1.png
│   ├── physicist_amortized_2.png
│   ├── physicist_amortized_3.png
│   └── physicist_amortized_4.png
├── bigO.md
├── leetcode
│   ├── 1456 Maximum Number of Vowels in a Substring of Given Length.cpp
│   └── README.md
├── LICENSE
└── README.md

24 directories, 96 files
```

## Time complexity 

Consider the following algorithm for calculating nth Fibonacci number.

![image](https://user-images.githubusercontent.com/103832825/213064383-fde80516-e343-4982-92ad-4e36f17c0190.png)

Thus, we start by creating an array. We assigned the 0th element to 0. The first element to 1. Then, we have this big for loop where we set the i'th element to the sum of the i minus first and i minus second elements and then at the end of the day we return the nth element. So we determined that when we ran this program we executed about 2n + 2 lines of code. 

But we should really ask ourselves, is this number of lines of code executed really sort of an accurate description of the runtime of the algorithm? Somehow, implicitly, this measure of lines of code assumes that, sort of, any two lines of code are sort of comparable to each other, which may not be true always.

Thus, the time it will take for the computer to run this code depends on severaal factors such as system architecture, compiler, memory organizations etc. which may vary from computer to computer drastically. Thus this is not such an efficient measure of time.

Hence, we find time complexity such that it tells us how our <b>runtime</b> scales with <b>input size</b>, and not necessarily how long it actually takes in terms of real seconds, minutes, and hours. 

This is generally denoted by <b>Big-O</b> such as O(nlogn)

![image](https://user-images.githubusercontent.com/103832825/213328248-1b7095f6-08e0-4202-ab2a-7ef6acfbf2eb.png)

<a href = "https://github.com/PritK99/data-structures-and-algorihms/blob/main/bigO.md" >Click here</a> to see plots of various functions (such as logarithm, polynomial, exponent) and understand rules of Big-O.

### A few noteworthy points :- 
1) Pointers always take up 8 bytes of space in 64 bit architecture 
2) Struct involves padding while allocating memory , so even a struct of an int and char takes 8 bytes , while the struct of char takes 1 byte
3) Switch statements are much more faster than if-else statements. Switch behave similar to hashmaps, while if-else behave similar to linear search.
