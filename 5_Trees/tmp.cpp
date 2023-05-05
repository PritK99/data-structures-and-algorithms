#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string simplifyPath(string path)
{
    stack<char> st;
    int x = path.size();

    if ((path[x-1] >= 'a' && path[x-1] <= 'z' ) || path[x-1] == '.' )
    {
        path = path + '/' ;
        x++ ;
    }

    for (int i = 0; i < x; i++)
    {
        if (st.empty() && path[i] == '/')
        {
            st.push('/');
        }
        else if (!st.empty() && st.top() == '/' && path[i] == '/')
        {
            continue;
        }
        else if (path[i] == '.')
        {
            if (x - i > 1)
            {
                if (path[i + 1] == '.')
                {
                    if (x - i - 1 > 1)
                    {
                        if (path[i + 2] == '/')
                        {
                            // This represent normal with ../ case
                            st.pop(); // pop the first /
                            while (!st.empty())
                            {
                                if (st.top() == '/')
                                {
                                    break;
                                }
                                st.pop();
                            }
                            i = i + 2;
                        }
                        else
                        {
                            // This represents cases like ..happy
                            while (path[i] != '/')
                            {
                                st.push(path[i]);
                                i++;
                            }
                        }
                    }
                    else
                    {
                        // This represnt ending with .. case
                        st.pop(); // pop the first /
                        while (!st.empty())
                        {
                            if (st.top() == '/')
                            {
                                break;
                            }
                            st.pop();
                        }
                        break;
                    }
                }
                else
                {
                    // This represents cases like .happy
                    while (path[i] != '/')
                    {
                        st.push(path[i]);
                        i++;
                    }
                }
            }
            else
            {
                break; // This is the case where the path ends with a .
            }

            if (path[i + 1] == '.' && path[i + 2] != '/')
            {
                // st.push('.') ;
                while (path[i] != '/' && i != path.size())
                {
                    st.push(path[i]);
                    i++;
                }
            }
            if (path[i + 1] == '.')
            {
                st.pop(); // pop the first /
                while (!st.empty())
                {
                    if (st.top() == '/')
                    {
                        break;
                    }
                    // cout << st.top();
                    st.pop();
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            st.push(path[i]);
        }
    }

    if (!st.empty())
    {
        if (st.top() == '/')
        {
            st.pop(); // To remove the extra slash at the end
        }
    }

    string answer;

    if (st.empty())
    {
        answer = "/";
    }
    else
    {
        while (!st.empty())
        {
            answer += st.top();
            st.pop();
        }
        reverse(answer.begin(), answer.end());
    }

    return answer;
}

int main()
{
    string s = "/a/./b/../../c/";
    string x = simplifyPath(s);
    cout << x;

    return 0;
}