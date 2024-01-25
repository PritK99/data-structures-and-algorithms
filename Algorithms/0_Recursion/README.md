# Recursion

## Introduction

Recursion is when a function calls itself either directly or indirectly. Typically the function performs some part of the task and rest is delegated to the recursive call of the same function. Hence, there are multiple instances of same function each performing some part of the overall task. Function stops calling itself when a terminating condition is reached.

The core intuition is that if we are able to express a problem in terms of smaller instances of the itself, then we can solve the problem using recursion.

The two components of recursion are:-

* Base case: This is the terminating case.
* Recursive case: Recursive function performs some part of task and delegate rest of it to the recursive call.

## How Recursion looks in Memory

When a program, represented by an executable (```.exe``` or ```.out```), is executed, it becomes a process and is allocated space in RAM known as the Process Address Space. This is managed by the operating system and is divided into four main segments:

* Code Segment: This is the segment where the executable code is stored. The size of CS is fixed during load time.

* Data Segment: This is the segment where the global and static variables are stored. These values, if not initialized, are initialized with zero. The size of DS is fixed during load time and does not change during execution. Here, the variables are divided into two categories: initialized and uninitialized. The uninitialized variables are initialized with zeros together at the load time.

* Stack Segment: This contains the activation of all active functions. Main is also a function and is always called first. The OS calls the main function. The activation record holds metadata of the function such as parameters, return value, calling function, etc. The size of stacks keeps changing during execution. The uninitialized variables are assigned garbage value here. The rationale behind not initializing local variables is to avoid unnecessary overhead, as initializing every variable would incur a performance cost. This is different from DS, where it takes the compiler only one memset call to initialize all variables to zeros if uninitialized.

* Heap Segment: This is the segment where dynamic memory is allocated. The size of the Heap is not fixed during load time. Both the stack and heap share a common area in memory, where they grow towards each other.