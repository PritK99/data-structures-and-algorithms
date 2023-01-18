#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops, int n )
{
    int i = 0, no_of_refuels = 0;
    int capacity = tank;

    while (i < n+1 )
    {
        if (stops[i] <= tank)
        {
            i++;
        }
        else if (stops[i] > tank)
        {
            if (i == 0)
            {
                return -1;
            }
            no_of_refuels++;
            tank = stops[i - 1] + capacity;
            if (stops[i] > tank)
            {
                return -1;
            }
        }
    }

    return no_of_refuels;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    stops[n] = d ;
    cout << compute_min_refills(d, m, stops, n) << "\n";

    return 0;
}
