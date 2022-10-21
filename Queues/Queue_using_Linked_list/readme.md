# Queue using Linked List 

Here , we make use of two pointers called front and rear. Rear pointer is where insertion of element takes place and front is where deletion takes place.
Initially the front pointer points to the first element of queue. During deletion, value is deleted dynamically using delete keyword and the front pointer is incremented. Thus the time complexity is in terms of O(1).
Also , during insertion , a new node is created dynamically using malloc() function rear pointer is made to point at this new node 
It is very important to delete the node during dequeue() , since not doing so may lead to memory-leak. 
Also, we reset both front and rear pointers in case of queue being empty.

While using Linked-List , since we deal with heaps and dynamic memory , generally we can create as many nodes we want , till the heap memory gets finished.

Thus the advantages of using a linked list over array is that both insertion and deletion takes place in O(1) time complexity and the memory is dynamic in nature.
