/***************************************************
    @brief        Solving the Tower of Hanoi problem
****************************************************/
#include <iostream>
#include <stack>

using namespace std;

/*
 * Function Name: towerOfHanoi
 * Input: Requires number of disks, source, destination and extra rod
 * Logic: Transfers disks from source to destination using extra rod.
 * Example Call: towerOfHanoi(n, source, destination, extra) ;
 */
void towerOfHanoi(int n, stack<int> &source, stack<int> &destination, stack<int> &extra)
{
    if (n <= 0)
    {
        return;
    }

    towerOfHanoi(n - 1, source, extra, destination); // Move n-1 disks to extra rod
    int x = source.top();
    source.pop();
    destination.push(x);
    towerOfHanoi(n - 1, extra, destination, source); // For recursively treating the rest n-1 disks
}

int main()
{
    stack<int> source, destination, extra;

    int n = 4;

    // Filling source stack with initial discs where numbers denote size of disk
    source.push(4);
    source.push(3);
    source.push(2);
    source.push(1);

    towerOfHanoi(n, source, destination, extra);

    for (int i = 0; i < n; i++)
    {
        int x = destination.top();
        destination.pop();
        cout << x << " ";
    }

    return 0;
}
/*
Analysis: The above code runs in O(2^n), where n is the number of disks
*/
