#include <iostream>
#include <string>
#include <vector>

using namespace std ;

int main ()
{
    string s ; 
    cin >> s ;

    int size = s.length() ;
    vector<int> nums (size);

    //converting string to vector for ease
    for (int i = 0 ; i < size ; i++ )
    {
        nums[i] = s[i] - '0' ;
    }

    // for (int i = 0 ; i < size ; i++ )
    // {
    //     cout << nums[i] << " " ;
    // }

    int max_len = 0 ; 

    for (int i = 0 ; i < size ; i++)
    {
        for (int j = i + 1 ; j < size ; j+=2)   //Even strings
        {
            int lsum = 0, rsum = 0 ;
            int k = j-i ;   //k will always be even
            // cout << i << " " << k << " " << endl ;
            for (int p = i ; p <= i + (k/2) ; p++)
            {
                lsum += nums[p] ;
            }
            for (int p = i + (k/2) + 1 ; p <= j ; p++)
            {
                rsum += nums[p] ;
            }

            if (lsum == rsum)
            {
                if (k > max_len)
                {
                    // cout << k << endl ;
                    max_len = k ;
                }
            }
        }
    }

    max_len = max_len + 1 ;   //Indexing starts from 0

    cout << max_len ;
}