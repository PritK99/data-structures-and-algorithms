/*In this program, we will sort a list of elements using selection sort*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s; 
    getline(cin, s);

    int num = 0;
    vector<int> v;

    /*Taking input from the user and storing it in a vector of int*/
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
            v.push_back(num), num = 0;
        else
            num = num*10 + (s[i]-'0');
    }   
    v.push_back(num);

    auto iter = v.begin() ;

    while (iter != v.end())
    {
        auto min = min_element(iter, v.end()) ;
        int min_index = distance(v.begin(), min) ;

        /*Swapping the first value of remaining array with minimum value present in the remaining array*/
        int temp = v[min_index] ;
        v[min_index] = *iter ;
        *iter = temp ;

        iter++;
    }

    cout << "The sorted array using selection sort is : " ;
    for (int i = 0 ; i < v.size(); i++)
    {
        cout << v[i] << " " ;
    }
  
    return 0;
}