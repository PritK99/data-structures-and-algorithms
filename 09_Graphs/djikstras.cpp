#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<long long> djikstras(vector<vector<int>> &adj, vector<vector<int>> &cost, int s)
{
    vector<long long> distance(adj.size(), LLONG_MAX);
    vector<bool> visited(adj.size(), false);

    distance[s] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, s});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i];
            int weight = cost[u][i];

            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({-distance[v], v});
            }
        }
    }

    return distance;
}

int main()
{
    int num_vertices, num_edges;
    cin >> num_vertices >> num_edges;

    vector<vector<int>> adj(num_vertices, vector<int>());
    vector<vector<int>> cost(num_vertices, vector<int>());

    for (int i = 0; i < num_edges; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }

    int s, t;
    cin >> s >> t;
    vector<long long> shortest_path = djikstras(adj, cost, s - 1);

    if (shortest_path[t - 1] == LLONG_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << shortest_path[t - 1];
    }

    return 0;
}