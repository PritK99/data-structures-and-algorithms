#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std ;

vector<int> Merge(vector <int> left, vector <int> right)
{
    vector<int> merged ;
    auto p = left.begin() ;
    auto q = left.end() ;
    auto r = right.begin() ;
    auto s = right.end() ;

    while (p < q || r < s)
    {
        if (p == q && r<=s)
        {
            merged.push_back(*r) ;
            r++ ;
        }
        else if (p < q && r == s)
        {
            merged.push_back(*p) ;
            p++ ;
        }
        else
        {
            if (*p < *r)
            {
                merged.push_back(*p) ;
                p++ ;
            }
            else
            {
                merged.push_back(*r) ;
                r++ ;
            }
        }

    }

    return merged ;
}

vector<int> MergeSort (vector<int> A, int begin, int end)
{
    vector<int> sorted ;
    if(end - begin == 1)
    {
        vector<int> temp ;
        temp.push_back(A[begin]) ;
        return temp ;
    }
    int m = floor((end - begin)/2) ;
    vector<int> left = MergeSort(A, begin, begin+m) ;
    vector<int> right = MergeSort(A, begin+m, end) ;
    sorted = Merge(left, right) ;
    return sorted ;
}

int main ()
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

    vector<int> result = MergeSort(v, 0, v.size()) ;
    
    cout << "The sorted array using merge sort is : " ;
    for (int i = 0 ; i < result.size(); i++)
    {
        cout << result[i] << " " ;
    }
}