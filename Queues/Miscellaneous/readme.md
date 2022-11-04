# Miscellaneous Contents

## 1) Queue using two stacks 
Here, we make use of 2 stacks to implement basic operations of queue such as enqueue and dequeue. In this method, in enqueue operation, the new element is always pushed on stack1. In de-queue operation, if stack2 is empty then all the elements in stack1 are moved to stack2 and finally stack2 is popped. This way we are able to implement FIFO using LIFO property of stacks.
