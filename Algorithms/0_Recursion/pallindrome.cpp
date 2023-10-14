/*********************************************************************
    @brief        Checking if the given string is a pallindrome or not
**********************************************************************/
#include <iostream>
using namespace std;

/*
 * Function Name: isPallindrome
 * Input: Takes the struct as input
 * Output: returns boolean true if given string is a pallindrome, else false.
 * Logic: This function recursively checks if given string is a pallindrome
 * Example Call: isPallindrome(s)
 */
bool isPallindrome(string s) 
{
    int n = s.size() - 1 ;

    // Base Case
    if (n == 0 || n == 1)
    {
        return true ;
    }

    // Recursive case
    if (s.front() == s.back())
    {
        return isPallindrome(s.substr(1, n-1)) ;
    }
    else
    {
        return false ;
    }
}

int main ()
{
    string s  ;
    cout << "Enter a string: " ;
    cin >> s ;
    cout << isPallindrome(s) ;

    return 0;
}
/*
Analysis: The above algorithm runs in O(n)
*/