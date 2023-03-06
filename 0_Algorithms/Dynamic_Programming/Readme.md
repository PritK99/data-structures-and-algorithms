## Dynamic Programming

### Introduction

The greedy approach, though is very easy to think, does not always work. Imagine someone had to return me 40 cents. First, finding the largest coin denomination that is smaller than 40 cents. It will be 25 cents. So he will give me 25, 15 cents left and then the next challenge is how to change 15 cents.
The next step is probably finding the largest coin smaller than 15 cents, it is 10 cents and finally, 5 cents.  It is the minimal number of coins in the United States. But if you travel to Tanzania, it won't be the minimum number of coins because there is a 20 cent coin in Tanzania. And therefore this greedy approach to solving the change problem will fail in Tanzania because there is a better way to change 40 cents, simply as 20 cents plus 20 cents, using Tanzanian 20 cents coin.

Another approach is a recursive way to deal with this problem as given in ```recursive_coin_change.cpp```, but clearly, this approach would take a lot of time. Thus we go for dynamic programming.

In dynamic programming, rather than thinking how can we break the change into smaller coins, we try to think how can we build that change using minimum coins step by step. For eg. to get a chnage of 9 from coins of 1,