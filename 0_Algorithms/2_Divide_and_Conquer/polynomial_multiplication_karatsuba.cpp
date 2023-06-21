#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int *Multiply(vector <int> &A, vector <int> &B, int left1, int right1, int left2, int right2)
{
    if (right1 - left1 == 1 )
    {
        
    }
}

int main()
{
    int n;
    cout << "Please enter the maximum degree of polynomial : ";
    cin >> n;

    vector<int> A(n + 1), B(n + 1);

    cout << "Please enter coefficients for first polynomial : ";

    for (int i = 0; i < n + 1; i++)
    {
        cin >> A[i];
    }

    cout << "Please enter coefficients for second polynomial : ";

    for (int i = 0; i < n + 1; i++)
    {
        cin >> B[i];
    }

    Multiply(A, B, 0, n, 0, n);

    int C[2 * n + 1] = {0};

    return 0 ;
}