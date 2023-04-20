## Dynamic Programming

```
Thus, I thought dynamic programming was a good name. It was something not even a Congressman could object to.

                                                                                      ~ Richard Bellman
```

### Why Dynamic Programming ?

The greedy approach, though is very easy to think, does not always work. Another approach is a recursive way to solve problems, but this approach at time leads to very bad time complexities. The problem with this approach is that we solve the same sub-problems several times.

Thus we go for dynamic programming, which is essentially performing recursion smartly. 

## When to apply Dynamic Programming ?

The two conditions where we can apply dynamic programming are:-
* optimal substructure 
* overlapping solutions

    ### Optimal Substructure 

    Optimal substructure means that the optimal solution to a problem of size n is based on an optimal solution of same problem of smaller size, say n-1. In other words, while building the solution for a problem of size n, define it in terms of smaller size and combine it in the end to get solution to original problem.

    ### Overlapping Solutions

    Overlapping solutions are found when recursive function is called with exactly same parameters more than once. In this case we say that a subproblem is solved multiple times.  Had we been solving a subproblem only once, the code would have
    been really fast, even if we are using recursion. Memoization, Dynamic
    programming and Greedy approach are techniques used to solve this classic
    problem.

## How to apply Dynamic Programming

There are two approach in dynamic programming:-

* Memoization
* Bottom-up approach

    ### Memoization

    The first approach is top-down with memoization. In this approach, we write the procedure recursively in a natural manner, but modified to save the result of each subproblem in some cache. The procedure now first checks to see whether it has previously solved this subproblem. If so, it returns the saved value, saving further computation at this level; if not, the procedure computes the value in the usual manner. We say that the recursive procedure has been memoized; it “remembers” what results it has computed previously.

    Deciding data structure of cache is important step in memoization. The cache should be capable of storing results of all subproblems. Usually cache is an array or hash table. If our problem has only one parameter, then we can go for 1D-Arrays. However, if there are multiple parameters to be considered, we use multi-dimensional array.

    ### Bottom-Up approach

    The second approach is the bottom-up method. This approach typically depends on some natural notion of the “size” of a subproblem, such that solving any particular subproblem depends only on solving “smaller” subproblems. We sort the subproblems by size and solve them in size order, smallest first. When solving a particular subproblem, we have already solved all of the smaller subproblems its solution depends upon, and we have saved their solutions. We solve each subproblem only once, and when we first see it, we have already solved all of its prerequisite subproblems.

Dynamic programming thus uses additional memory to save computation time; it serves an example of a time-memory trade-off. The savings however are massive: an exponential-time solution may be transformed into a polynomial-time solution.


