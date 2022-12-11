#include <iostream>

using namespace std;

class Graph
{
private:
    int no_of_vertices;
    int no_of_edges;
    int **adj_matrix;

public:
    void make_graph(int no_of_vertices, int no_of_edges);
    void add_edge();
    void kruskals();
};

void Graph ::make_graph(int no_of_vertices, int no_of_edges)
{
    this->no_of_vertices = no_of_vertices;
    this->no_of_edges = no_of_edges;

    // creating a graph
    adj_matrix = new int *[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adj_matrix[i] = new int[no_of_vertices];
        // initializing all the elements of graph
        for (int j = 0; j < no_of_vertices; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }
}

void Graph ::add_edge()
{
    for (int i = 0; i < no_of_edges; i++)
    {
        int temp_i, temp_j;
        cin >> temp_i >> temp_j;
        adj_matrix[temp_i - 1][temp_j - 1] = 1;
    }
}

void Graph ::kruskals()
{
    /* Initializing a array to keep a record of families of each vertex
    index 0 of array means 0th vertex and so on*/
    int sets[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        sets[i] = i; // This step makes all the vertices a parent of themselves
    }

    while (no_of_edges--)
    {
        /*we run the while loop for the total no of edges*/
        /*first we find the edge with the minimum weight*/
        int min = -1;
        int temp_i = 0, temp_j = 0;
        for (int i = 0; i < no_of_vertices; i++)
        {
            for (int j = 0; j < no_of_vertices; j++)
            {
                if (adj_matrix[i][j] > 0)
                {

                    temp_i = i;
                    temp_j = j;

                    int temp_1 = sets[temp_i];
                    int temp_2 = sets[temp_j];

                    if (sets[temp_i] != sets[temp_j])
                    {
                        for (int i = 0; i < no_of_vertices; i++)
                        {
                            /*Convert the entire family of second vertex to first family*/
                            if (sets[i] == temp_2)
                            {
                                sets[i] = temp_1;
                            }
                        }
                    }

                    adj_matrix[temp_i][temp_j] = 0; // we have made cost of that path 0 to avoid recomparison
                }
                else
                {
                    continue;
                }
            }
        }
    }

    int counter = 0;

    for (int i = 0; i < no_of_vertices; i++)
    {
        if (sets[i] == -1)
        {
            // explored set
            continue;
        }
        else
        {
            // convert the entire family to -1
            counter++;
            int temp = sets[i];
            sets[i] = -1;
            for (int j = 0; j < no_of_vertices; j++)
            {
                if (sets[j] == temp)
                {
                    sets[j] = -1;
                }
            }
        }
    }

    cout << counter ;
}

// main function starts here
int main()
{
    Graph g;
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    g.make_graph(no_of_vertices, no_of_edges);
    g.add_edge();
    g.kruskals();

    return 0;
}
// end of main