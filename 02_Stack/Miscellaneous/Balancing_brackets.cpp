/*******************************************
    @brief        Balancing brackets in text
********************************************/

#include <iostream>
#define MAX_SIZE 10000
using namespace std;

class Stack
{
private:
    char stack[MAX_SIZE];
    int top = -1;

public:
    void push(char element);
    char pop();
    char peek();
};

/*
 * Function Name: push
 * Input: Integer element which is to be pushed
 * Output: None
 * Logic: This function allows us to insert an element in stack
 * Example Call: push(5)
 */
void Stack ::push(char element)
{
    if (top != MAX_SIZE - 1) // We can not push anymore elements if the stack is full
    {
        top++;
        stack[top] = element;
    }
}

/*
 * Function Name: pop
 * Input: None
 * Output: Returns the topmost element of stack or -1 if stack is empty
 * Logic: This function allows us to remove an element from stack
 * Example Call: pop()
 */
char Stack ::pop() 
{
    if (top != -1)
    {
        return stack[top--];
        /* We need to do top-- above itself cause the staements below the return statement are not executed*/
    }
    else
    {
        return 'X';
    }
}
// end of function

/*
 * Function Name: peek
 * Input: None
 * Output: Returns the topmost element of stack or -1 if stack is empty without deleting it
 * Logic: This function allows us to remove an element from stack without deleting it
 * Example Call: peek()
 */
char Stack ::peek()
{
    if (top != -1)
    {
        return stack[top]; // here, we simply return the topmost element and not decrement top
    }
    else
    {
        return 'X';
    }
}

int main()
{
    Stack s1;

    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if (s[i] == ')' && s1.peek() == '(')
            {
                char x;
                x = s1.pop();
            }
            else if (s[i] == ']' && s1.peek() == '[')
            {
                char x;
                x = s1.pop();
            }
            else if (s[i] == '}' && s1.peek() == '{')
            {
                char x;
                x = s1.pop();
            }
            else
            {
                s1.push(s[i]);
            }
        }
    }

    // if stack is empty by now, the expression is valid
    char x;
    x = s1.peek();
    if (x == 'X')
    {
        cout << "Success"<<"\n";    
    }
    else
    {
        x = s1.peek() ;
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (x == s[i])
            {
                cout << i+1 ;   //to print location of error
                break ;
            }
        }
    }

    return 0;
}
// end of main