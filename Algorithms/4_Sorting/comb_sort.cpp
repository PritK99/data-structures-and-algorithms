/***************************************
    @brief        Implementing Comb Sort
****************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Function Name: comb_sort
 * Input: unsorted vector
 * Output: sorted vector
 * Example Call: comb_sort(v)
 */
vector <int> comb_sort (vector <int> v)
{
    // Defining the gap value
    int gap = int(v.size() / 1.3);
    bool is_swap = 1;

    while (!((gap==1) && (is_swap==0)))
    {
        // Reset the value of is_swap
        is_swap = 0;
        for (int i = 0; i < v.size()-gap; i++)
        {
            if (v[i] > v[i+gap])
            {
                is_swap = 1;
                int temp = v[i];
                v[i] = v[i+gap];
                v[i+gap] = temp;
            }
        }

        // Update the value of gap using previous
        gap = max(int(gap / 1.3),1);
    }

    return v;
}

int main()
{
    int n;

    string s;
    getline(cin, s);

    int num = 0;
    vector<int> v;

    // Taking input from the user and storing it in a vector of int
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num * 10 + (s[i] - '0');
    }
    v.push_back(num);

    vector <int> result = comb_sort(v);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Analysis: The above algorithn runs in O(n^2).
*/