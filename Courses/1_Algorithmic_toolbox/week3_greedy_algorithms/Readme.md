# Greedy Algorithms

## Introduction
A greedy algorithm builds a solution piece by piece and at each step, chooses the most profitable piece.

Consider a problem to find largest number that can be obtained by concatenating the given numbers. 

For example, for the input sequence (2,3,9,1,2), the output is the number 93221. Clearly, the largest single-digit number should be selected as the first digit of the concatenate. Afterward, we face essentially the same problem: concatenate the remaining numbers to get as large number as possible.

Thus the general algorithm for this 
![image](https://user-images.githubusercontent.com/103832825/212585316-f4235fbd-58bc-40d3-9f81-eef5da831b87.png)

![image](https://user-images.githubusercontent.com/103832825/212585382-70feacc0-bac6-4bef-be3b-5a68e9622bf5.png)


# Drawbacks
If you use the same greedy strategy, then LargestConcatenate([2,21]) returns 212 and Change(8,[1,4,6]) returns 3 because 8 = 6+1+1. 

But this strategy fails because the correct solutions are 221 (concatenating 2 with 21) and 2 because 8=4+4!
