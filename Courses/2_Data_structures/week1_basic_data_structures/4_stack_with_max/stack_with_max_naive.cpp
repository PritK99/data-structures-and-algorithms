/*This code introduces us to stack as a data structures and basic operations on stack*/
#include <iostream>
#include <string>

#define MAX_SIZE 100 // The maximum number of elements a stack can hold is 100

using namespace std;

class Stack
{
private:
    int stack[MAX_SIZE];
    int top = -1;
    int min = 0;
    int max = 0;

public:
    void push(int element);
    int pop();
    int peek();
    int get_max();
};

/*This function allows us to insert an element in stack*/
void Stack ::push(int element)
{
    if (top != MAX_SIZE - 1) // We can not push anymore elements if the stack is full
    {
        top++;

        if (top == 0)
        {
            max = element;
            stack[top] = element;
        }
        else if (element > max)
        {
            stack[top] = 2 * element - max;
            max = element;
        }
        else
        {
            stack[top] = element;
        }
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
        if (peek() >= max)
        {
            int temp = max;
            max = 2 * max - stack[top--];
            return temp;
        }
        else
        {
            return stack[top--];
        }
        /* We need to do top-- with return itself cause the staements below the return statement are not executed*/
    }
    else
    {
        cout << "The stack is empty\n";
        return -1; // just to avoid the warning of control reaches end of non-void function
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
        cout << "The stack is empty\n";
        return -1; // just to avoid the warning of control reaches end of non-void function
    }
}
// end of function

int Stack ::get_max()
{
    return max;
}

int main()
{
    Stack s1;
    int x;

    int n;
    cin >> n;
    string query;
    for (int i = 0; i < n; i++)
    {
        cin.getline(query , 80) ;;
        if (query[0] == 'm')
        {
            x = s1.get_max();
            cout << x << endl;
        }
        else if (query[0] == 'p' && query[1] == 'o')
        {
            x = s1.pop();
            cout<< x << endl;
        }
        else
        {
            cout << (int)query[5] ;
            s1.push((int)query[5] - 48) ;
        }
    }

    return 0;
}
// end of main