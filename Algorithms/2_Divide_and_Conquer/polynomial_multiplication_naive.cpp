/******************************************************************
    @brief        Naive implementation of polynomial multiplication
*******************************************************************/
#include <iostream>

using namespace std ;

int main ()
{
    int n ;
    cout << "Please enter the maximum degree of polynomial : " ;
    cin >> n ;

    int A[n+1] , B[n+1] ;

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

    int C[2*n+1] = {0} ;

    for (int i = 0 ; i < n+1 ; i ++)
    {
        for (int j = 0 ; j < n+1 ; j++)
        {
            C[i+j] = C[i+j] + A[i]*B[j];
        }
    }

    cout << "The coefficients of final polynomial are: (" ;
    
    for (int i = 0 ; i < 2*n + 1 ; i++)
    {
        if (i == 2*n)
        {
            cout << C[i] ;
            continue ;
        }
        cout << C[i] << ", " ;
    }
    cout << ")" << endl ;
}
/*
Analysis: The above code runs in O(n^2).
*/