#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longest_sequence(string string1, string string2, int i, int j, int count)
{
    if (i > 0 && j > 0)
    {
        if (string1[i - 1] == string2[j - 1])
        {
            count = longest_sequence(string1, string2, i-1, j-1, count+1) ;
        }
        else
        {
            int x, y ;
            x = longest_sequence(string1, string2, i-1, j, count) ;
            y = longest_sequence(string1, string2, i, j-1, count) ;
            count = max(x,y) ;
        }
    }

    return count;
}

int main()
{
    string string1, string2;
    cout << "Please enter the first sequence: ";
    cin >> string1;
    cout << "Please enter the second sequence: ";
    cin >> string2;

    int i = string1.length();
    int j = string2.length();

    int count = 0;

    int result = longest_sequence(string1, string2, i, j, count);
    cout << "The longest common sequence is: " << result;
    return 0;
}