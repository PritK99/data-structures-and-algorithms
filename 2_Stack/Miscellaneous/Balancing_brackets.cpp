/*Here, we are trying to implement a code to test brackets indentation
This code not only inform the user that there is an error in the usage of brackets, but also point to the exact place in the code with the problematic bracket. 
First priority is to find the first unmatched closing bracket which either doesn’t have an opening bracket before it,
like ] in ](), or closes the wrong opening bracket, like } in ()[}. If there are no such mistakes, then
it should find the first unmatched opening bracket without the corresponding closing bracket after it,
like ( in {}([]. If there are no mistakes, text editor should inform the user that the usage of brackets
is correct.
Apart from the brackets, code can contain big and small latin letters, digits and punctuation marks.*/

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

/*This function allows us to insert an element in stack*/
void Stack ::push(char element)
{
    if (top != MAX_SIZE - 1) // We can not push anymore elements if the stack is full
    {
        top++;
        stack[top] = element;
    }
}
// end of function

/*This function removes the topmost element of stack
if the function returns -1 , it implies stack is empty*/
char Stack ::pop() // We can not pop any elements if the stack is empty
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

/*This function simply returns the topmost element of stack without deleting it from the stack
if the function returns -1 , it implies stack is empty*/
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
// end of function

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