/*
Here, we use the divide and conquer technique to carry polynomial multiplications
*/
#include <iostream>

using namespace std ;

int multiply(int A[],int B[],int A_start,int A_end, int B_start, int B_end ,int n) 
{
    if (n == 1)
    {
        return A[A_start]*B[B_start] ;
    }
    cout << "pass1" ;
    return multiply(A, B, 0, (n+1)/2, 0, (n+1)/2, (n+1)/2) +  multiply(A, B, 0, (n+1)/2, 0, (n+1)/2, (n+1)/2) + multiply(A, B, 0, (n+1)/2, (n+1)/2, n, (n+1)/2) + multiply(A, B, (n+1)/2, n, 0, (n+1)/2, (n+1)/2);
}

int main ()
{
    int n ;
    cout << "Please enter the maximum degree of polynomial : " ;
    cin >> n ;

    if(n%2 == 0)
    {
        n = n+1 ;
    }

    int A[n+1] , B[n+1] ;
    int size = n+1 ;

    cout << "Please enter coefficients for first polynomial : " ;
    for (int i = 0 ; i < n+1 ; i++ )
    {
        cin >> A[i] ;
    }

    cout << "Please enter coefficients for second polynomial : " ;
    for (int i = 0 ; i < n+1 ; i++ )
    {
        cin >> B[i] ;
    }

    int x = multiply(A, B, 0, n, 0, n, (n+1)/2) ;
    cout << x << endl ;
}