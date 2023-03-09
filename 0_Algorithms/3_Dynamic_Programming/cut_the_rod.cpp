#include <iostream>
#include <vector>

using namespace std ;

int get_max_price(vector <int> length, vector <int> price, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0 ; j<size ; j++)
        {
        }
    }
}

int main ()
{
    int size ;
    cout << "Please enter the length of rod: " ;
    cin >> size;
    vector <int> length(size) ;
    vector <int> price(size) ;

    for (int i = 0 ; i < size ; i++)
    {
        length[i] = i ;
        cout << "Enter price of rod for length " << i+1 << ": " ;
        cin >> price[i] ;
    }

    int maximum = get_max_price(length, price, size);

}