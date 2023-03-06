#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ;

vector <int> QuickSort()
{
    
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

    vector<int> result ;
    result = QuickSort() ;

    return 0 ;
}