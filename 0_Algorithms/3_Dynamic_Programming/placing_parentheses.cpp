#include <iostream>
#include <vector>

using namespace std;

struct minmax
{
    long long int min = 999999999; 
    long long int max = -999999999;
};

long long int maximum(long long int a, long long int b, long long int c, long long int d)
{
    if (a > b && a > c && a > d)
    {
        return a;
    }
    else if (b > c && b > d)
    {
        return b;
    }
    else if (c > d)
    {
        return c;
    }
    return d;
}
long long int minimum(long long int a, long long int b, long long int c, long long int d)
{
    if (a < b && a < c && a < d)
    {
        return a;
    }
    else if (b < c && b < d)
    {
        return b;
    }
    else if (c < d)
    {
        return c;
    }
    return d;
}

struct minmax min_and_max(vector<vector<long long int>> maxima, vector<vector<long long int>> minima, vector<long long int> operand, vector<char> operation, long long int i, long long int j, struct minmax h)
{
    for (long long int k = i; k < j; k++)
    {
        long long int a, b, c, d;
        if (operation[k] == '+')
        {
            a = maxima[i][k] + maxima[k+1][j];
            b = maxima[i][k] + minima[k+1][j];
            c = minima[i][k] + maxima[k+1][j];
            d = minima[i][k] + minima[k+1][j];
        }
        else if (operation[k] == '-')
        {
            a = maxima[i][k] - maxima[k+1][j];
            b = maxima[i][k] - minima[k+1][j];
            c = minima[i][k] - maxima[k+1][j];
            d = minima[i][k] - minima[k+1][j];
        }
        else
        {
            a = maxima[i][k] * maxima[k+1][j];
            b = maxima[i][k] * minima[k+1][j];
            c = minima[i][k] * maxima[k+1][j];
            d = minima[i][k] * minima[k+1][j];
        }

        long long int x = maximum(a,b,c,d) ;
        long long int y = minimum(a,b,c,d) ;
        if ( x > h.max)
        {
            h.max = x ;
        }
        if ( y < h.min)
        {
            h.min = y ;
        }
    }
    
    return h;
}

long long int get_val(vector<long long int> operand, vector<char> operation)
{
    long long int n = operand.size();
    vector<vector<long long int>> maxima(n, vector<long long int>(n, 0));
    vector<vector<long long int>> minima(n, vector<long long int>(n, 0));

    for (long long int i = 0; i < n; i++)
    {
        minima[i][i] = maxima[i][i] = operand[i];
    }

    for (long long int d = 1; d < n; d++)
    {
        for (long long int i = 0, j = i + d; j < n; i++, j++)
        {
            minmax h;
            h = min_and_max(maxima, minima, operand, operation, i, j, h);
            maxima[i][j] = h.max;
            minima[i][j] = h.min;
        }
    }

    return maxima[0][maxima.size()-1];
}

int main()
{
    string s;
    cout << "Please enter your arithmetic expression: " ;
    cin >> s;
    vector<long long int> operand;
    vector<char> operation;

    int index = 0;
    bool input_flag = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[index] == '+' || s[index] == '-' || s[index] == '*' || s[index] == '/')
        {
            operation.push_back(s[index]);
            input_flag = 1;
        }
        else
        {
            if (input_flag == 1)
            {
                operand.push_back(s[index] - '0');
            }
            else
            {
                operand[operand.size() - 1] = 10 * operand[operand.size() - 1] + (s[index] - '0');
            }
            input_flag = 0;
        }
        index++;
    }

    long long int x = get_val(operand, operation) ;
    cout << "The maximum value of expression is: " <<  x ;

    return 0;
}