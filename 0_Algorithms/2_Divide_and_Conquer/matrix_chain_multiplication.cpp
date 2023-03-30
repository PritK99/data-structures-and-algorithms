#include <iostream>

using namespace std;

int MatrixMultiply(int dim[], int n )
{
    int solution[n][n] = {0};
    int k_val[n][n] = {0};
}


int main()
{
    int n;
    cout << "Please enter total number of matrices: ";
    cin >> n;

    int dim[n + 1];
    int buffer;

    if (n != 0)
    {
        cout << "Please enter the dimensions of matrix 1: ";
        cin >> dim[0];
        cin >> dim[1];

        for (int i = 2; i < n; i++)
        {
            cout << "Please enter the dimensions of matrix " << i - 1 << ": ";
            cin >> buffer; // To ignore the first index
            cin >> dim[i];
        }

        MatrixMultiply(dim, n) ;
    }
}