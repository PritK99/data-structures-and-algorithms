#include <iostream>

using namespace std;

long long int fibonacci(int n)
{
    int temp = n - 1;

    long long int matrix[2][2] = {1, 1, 1, 0};
    long long int matrix_result[2][2] = {0};

    while (temp != 1)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    matrix_result[i][k] += matrix[i][j] * matrix[j][k];
                }
            }
        }

        if (temp % 2 != 0)
        {
            long long int A[2][2] = {1, 1, 1, 0};

            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                    {
                        matrix_result[i][k] += A[i][j] * matrix[j][k];
                    }
                }
            }
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                matrix[i][j] = matrix_result[i][j];
                matrix_result[i][j] = 0;
            }
        }

        temp = temp / 2;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return matrix[0][0];
}

int main()
{
    int n;
    cout << "Please enter the value of n: ";
    cin >> n;

    long long int answer = fibonacci(n);
    cout << answer;
}