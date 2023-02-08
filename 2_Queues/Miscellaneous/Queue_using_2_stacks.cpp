/*This code implements queue using 2 stacks*/
#include <iostream>
#define MAX_SIZE 100 // The maximum number of elements a stack can hold is 100

using namespace std;

class Stack
{
private:
    int stack[MAX_SIZE];
    int top = -1;

public:
    void push(int element);
    int pop();
    int peek();
};

/*This function allows us to insert an element in stack*/
void Stack ::push(int element)
{
    if (top != MAX_SIZE - 1) // We can not push anymore elements if the stack is full
    {
        top++;
        stack[top] = element;
    }
    else
    {
        cout << "The stack is full\n";
    }
}
// end of function

/*This function removes the topmost element of stack
if the function returns -1 , it implies stack is empty*/
int Stack ::pop() // We can not pop any elements if the stack is empty
{
    if (top != -1)
    {
        return stack[top--];
        /* We need to do top-- above itself cause the staements below the return statement are not executed*/
    }
    else
    {
        return -1; 
    }
}
// end of function

/*This function simply returns the topmost element of stack without deleting it from the stack
if the function returns -1 , it implies stack is empty*/
int Stack ::peek()
{
    if (top != -1)
    {
        return stack[top]; // here, we simply return the topmost element and not decrement top
    }
    else
    {
        return -1; 
    }
}
// end of function

/*Enqueue function is ued to insert element in queue
while enqueueing, we always insert the element in stack 1*/
void enqueue(Stack *s1, int element)
{
    s1->push(element);
}
// end of function

/*dequeue function is ued to insert element in queue
while dequeuing, if stack2 is not empty, we pop it
else, we transfer contents of stack1 to stack2 and then pop stack2*/
int dequeue(Stack *s1, Stack *s2)
{
    int x;

    if (s2->peek() == -1) // if stack2 is not empty, directly pop from it
    {
        while (s1->peek() != -1) // transferring contents of stack1 in stack2
        {
            s2->push(s1->pop());
        }
    }
    x = s2->pop();

    return x;
}
// end of function

int main()
{
    Stack s1, s2;
    int x;

    enqueue(&s1, 50);
    enqueue(&s1, 250);

    x = dequeue(&s1 , &s2) ;
    cout << x << "\n";

    x = dequeue(&s1 , &s2) ;
    cout << x << "\n";

    x = dequeue(&s1 , &s2) ;
    cout << x << "\n";

    return 0;
}
// end of main