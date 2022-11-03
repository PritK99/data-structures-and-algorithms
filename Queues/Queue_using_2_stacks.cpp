/* 1 means to enqueue , 2 means to deque , 3 means to print front element */
#include <iostream>

using namespace std;

class Stack
{
private:
    int arr[10000];

public:
    int top; // points at the topmost element in a stack
    void push(int element);
    void pop();
    void peek();
}; // creating two stacks

void Stack ::push(int element)
{
    if (stack_1.top == -1)
    {
        stack_1.top = 0;
        arr[stack_1.top] = element;
        stack_1.top++;
    }
    else
    {
        arr[stack_1.top] = element;
        stack_1.top++;
    }
}
// end of function

void Stack ::pop()
{
    stack_2.top = 0; // the top points towards the first element of stack_2 , since pop will only be called for stack_2

    while (stack_1.top >= 0)
    {
        stack_2.top = stack_1.top;
        stack_2.top++;
        stack_1.top--;
    }

    cout << arr[stack_2.top] << "\n";
    stack_2.top--;

    stack_1.top = stack_1.arr; // reseting the pointer for first stack

    while (top < 0)
    {
        stack_1.arr[stack_1.top] = stack_2.arr[stack_2.top] stack_2.top--;
        stack_1.top++;
    }
}
// end of function

void Stack ::peek()
{
    stack_2.top = 0; // the top points towards the first element of stack_2 , since pop will only be called for stack_2

    while (stack_1.top >= 0)
    {
        stack_2.top = stack_1.top;
        stack_2.top++;
        stack_1.top--;
    }

    cout << arr[stack_2.top] << "\n";

    stack_1.top = stack_1.arr; // reseting the pointer for first stack

    while (top < 0)
    {
        stack_1.arr[stack_1.top] = stack_2.arr[stack_2.top] stack_2.top--;
        stack_1.top++;
    }
}
// end of function

int main()
{

    Stack stack_1, stack_2;

    int no_of_queries;
    cin >> no_of_queries;

    while (no_of_queries--)
    {
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int element;
            cin >> element;
            stack_1.push(element);
        }
        else if (choice == 2)
        {
            stack_2.pop();
        }
        else
        {
            stack_2.peek();
        }
    }
}