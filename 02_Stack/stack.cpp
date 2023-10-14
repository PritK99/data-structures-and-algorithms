/*******************************************************************
    @brief        Implementing stack and performing basic operations
********************************************************************/

#include <iostream>
#define MAX_SIZE 100 // The maximum number of elements our stack can hold is 100
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

/*
 * Function Name: push
 * Input: Integer element which is to be pushed
 * Output: None
 * Logic: This function allows us to insert an element in stack
 * Example Call: push(5)
 */
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

/*
 * Function Name: pop
 * Input: None
 * Output: Returns the topmost element of stack or -1 if stack is empty
 * Logic: This function allows us to remove an element from stack
 * Example Call: pop()
 */
int Stack ::pop()
{
    if (top != -1)
    {
        return stack[top--];
        /* We need to do top-- above itself cause the staements below the return statement are not executed*/
    }
    else
    {
        cout << "The stack is empty\n";
        return -1; // just to avoid the warning of control reaches end of non-void function
    }
}

/*
 * Function Name: peek
 * Input: None
 * Output: Returns the topmost element of stack or -1 if stack is empty without deleting it
 * Logic: This function allows us to remove an element from stack without deleting it
 * Example Call: peek()
 */
int Stack ::peek()
{
    if (top != -1)
    {
        return stack[top]; // here, we simply return the topmost element and not decrement top
    }
    else
    {
        cout << "The stack is empty\n";
        return -1; // just to avoid the warning of control reaches end of non-void function
    }
}

int main()
{
    Stack s1;
    int x;

    s1.push(50);
    s1.push(100);
    s1.push(150);

    x = s1.peek();
    cout << x << "\n";

    x = s1.pop();
    cout << x << "\n";
    x = s1.pop();
    cout << x << "\n";
    x = s1.pop();
    cout << x << "\n";

    x = s1.pop();
    cout << x << "\n";

    return 0;
}

/*
Analysis: The above code runs in O(1) for push, pop and peek.
*/