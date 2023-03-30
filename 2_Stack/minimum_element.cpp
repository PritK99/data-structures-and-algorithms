/******************************************************************
    @brief        Implementing stack and extracting minimum element
*******************************************************************/

#include <iostream>
#define MAX_SIZE 100 // The maximum number of elements our stack can hold is 100
using namespace std;

class Stack
{
private:
    int stack[MAX_SIZE];
    int top = -1;
    int min = INT_MAX;
    int max = INT_MIN;

public:
    void push(int element);
    int pop();
    int peek();
    int get_min();
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
        if (top == -1)
        {
            min = element ;
        }
        if (element < min && top != -1)
        {
            int temp = element ;
            element = element - min  ;
            min = temp ;
        }
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
        if (peek() < min)
        {
            int temp = min ;
            min = temp - peek() ;
            // cout << "min is: " << min << endl ;
            top -- ;
            return temp ;
        }
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

int Stack:: get_min ()
{
    if (top == -1)
    {
        return -1 ;
    }
    return min ;
}

int main()
{
    int n ;
    cin >> n ;
    Stack s1;
    int x;
    
    for (int i = 0 ; i < n ; i++)
    {
        int choice ;
        cin >> choice ;
        
        if (choice == 1)
        {
            int element ;
            cin >> element ;
            s1.push(element) ;
        }
        else if(choice == 2)
        {
            s1.pop() ;
        }
        else 
        {
            x = s1.get_min() ;
            cout << x << "\n";
        }
    }

    return 0;
}

/*
Analysis: The above code runs in O(1) for extracting minimum element.

Aliter: The same thing can be implemented by using 3 stacks, one to hold elements, one for maximum element and one for minimum element.

Note: The same code works for extracting maximum element by modifying few conditions.
*/