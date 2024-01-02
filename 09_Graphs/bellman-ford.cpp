#include <iostream>
#include <vector>
#include <climits>

using std::vector;

vector<int> negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost, int s)
{
    int v = adj.size();
    vector<bool> visited(v);

    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    for (int k = 0; k < v - 1; k++)
    {
        // Run v-1 interations

        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (dist[i] + cost[i][j] < dist[adj[i][j]] && dist[i] != INT_MAX)
                {
                    dist[adj[i][j]] = dist[i] + cost[i][j];
                }
            }
        }
    }

    while (1)
    {
        vector<int> temp = dist;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (dist[i] == INT_MIN || dist[i] + cost[i][j] < dist[adj[i][j]])
                {
                    dist[adj[i][j]] = INT_MIN;
                }
            }
        }
        if (temp == dist)
        {
            break;
        }
    }

    return dist;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    int s;
    std::cin >> s;
    vector<int> dist = negative_cycle(adj, cost, s - 1);

    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] == INT_MAX)
        {
            std::cout << "*";
        }
        else if (dist[i] == INT_MIN)
        {
            std::cout << "-";
        }
        else
        {
            std::cout << dist[i];
        }
        std::cout << std::endl;
    }
}
