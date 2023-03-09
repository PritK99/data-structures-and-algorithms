## Dynamic Programming

```
Thus, I thought dynamic programming was a good name. It was something not even a Congressman could object to.

                                                                                      ~ Richard Bellman
```

### Introduction

The greedy approach, though is very easy to think, does not always work. Another approach is a recursive way to deal with this problem is using the top-down approach, but clearly, this approach would take a lot of time. The problem with this approach is that we solve the same sub-problems several times. 

Thus we go for dynamic programming, which follows a bottom-top approach, unlike recursion, which is top-down approach. A dynamic-programming algorithm solves each subproblems just once and then saves its answer in a table, thereby avoiding the work of recomputing the answer every time it solves another subproblem. There are two approach in dynamic programming:- 

* The first approach is top-down with memoization. In this approach, we write the procedure recursively in a natural manner, but modified to save the result of each subproblem (usually in an array or hash table). The procedure now first checks to see whether it has previously solved this subproblem. If so, it returns the saved
value, saving further computation at this level; if not, the procedure computes the value in the usual manner. We say that the recursive procedure has been memoized; it “remembers” what results it has computed previously.

* The second approach is the bottom-up method. This approach typically depends on some natural notion of the “size” of a subproblem, such that solving any particular subproblem depends only on solving “smaller” subproblems. We sort the subproblems by size and solve them in size order, smallest first. When solving a
particular subproblem, we have already solved all of the smaller subproblems its solution depends upon, and we have saved their solutions. We solve each subproblem only once, and when we first see it, we have already solved all of its prerequisite subproblems.

Dynamic programming thus uses additional memory to save computation time; it serves an example of a time-memory trade-off. The savings may be dramatic: an exponential-time solution may be transformed into a polynomial-time solution.

In dynamic programming for the coin change problem, rather than thinking how can we break the change into smaller coins, we try to think how can we build that change using minimum coins step by step. For eg. 

![image](https://user-images.githubusercontent.com/103832825/223014197-ad0a5185-a6b3-46a5-af2f-28338813646a.png)

<a href="https://www.cs.usfca.edu/~galles/visualization/DPChange.html">Click here</a> to compare various algorithms for coin change.

For each of the examples, I have tried to present it with a naive solution first (generally using recursion) and then the solution using dynamic programming. For eg. ```coin_change_naive.cpp``` is a brute force solution to coin change problem using recursion, while ```coin_change.cpp``` is solution using dyanmic programming.

