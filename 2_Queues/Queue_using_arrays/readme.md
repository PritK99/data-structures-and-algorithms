# Queues using arrays 

## 1) Using arrays and one pointer only
Here , we use a single pointer called rear. The rear pointer is used to insert an element in the array. During insertion, we first check if the queue has space . If it has, the pointer is incremented and the value at the pointer is modified. Else, a message "Queue is full!" is displayed.
The time taken for insertion is in terms of O(1)

For deletion , we always delete the element at zero index and then shift the entire array to left. If the queue is empty however , "Queue is empty!" message is displayed.
The time taken for deletion is in terms of O(n)

## 2) Using arrays and two pointer
Here, we use two pointers called rear and front. Rear pointer is used to insert an element at the end, while front pointer is used to delete an element. 
For insertion, the method is same as we did in case of one pointer, hence taking O(1) time.

However, for deletion, we use front pointer. Initially the front pointer points to the first element of queue. During deletion, value is deleted and the front pointer is incremented. Thus the time complexity is in terms of O(1) 

Here, if the front pointer is greater than the rear pointyer , the queue is empty. Also, if rear == NULL, the queue is empty.
Also, if rear points to the last element possible in array , queue is full. 

## Drawbacks 
1) Since array come under static memory allocation, we can not increase or decrease the size of array it as per our needs
2) While using two pointers, the element space can't be accessed or used once the element in that space is deleted. Thus we can not reuse the space. Further, once front pointer becomes greater than rear pointer, No more element can be added to the queue

## Solutions
1) We can reset the pointers to their original position if front becomes greater than rear
2) We can use circular queues
