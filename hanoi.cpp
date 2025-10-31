#include <iostream>
#include <stack>

using namespace std;

// Defining Source, Destination and Extra Peg
stack <int> S;
stack <int> D;
stack <int> E;

void shift_upper(stack <int> source, stack <int> dest, stack <int> extra)
{

}

void hanoi(stack <int> source, stack <int> dest, stack <int> extra)
{
    if (source.empty())
    {
        cout << "Source Peg is Empty\n";
        return;
    }
    else if (source.size() == 1)
    {
        int x = source.top();
        source.pop();
        dest.push(x);
    }
    else
    {
        shift_upper(source, extra, dest);
        int x = source.top();
        source.pop();
        dest.push(x);
    }
}

int main()
{

}