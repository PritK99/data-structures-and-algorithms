/*
Code to create a minimum spanning tree graph using Kruskal's algorithm using Adjacency Matrix representation
We consider the graph to be undirected graph and weighted with no self loops
*/
#include <iostream>

using namespace std;

class Graph
{
private:
    int no_of_vertices;
    int no_of_edges = 0;
    int **adj_matrix;

public:
    void make_graph(int no_of_vertices);
    void display();
    void add_edge();
    void kruskals();
};

/*
This function is used to create a graph
parameters : no_of_vertices
Returns : void
*/
void Graph ::make_graph(int no_of_vertices)
{
    this->no_of_vertices = no_of_vertices;

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
// end of function

/*
This function is used to display the graph
parameters : void
Returns : void
*/
void Graph ::display()
{
    cout << "The adjacency matrix representation is :-\n";
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = 0; j < no_of_vertices; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
// end of function

/*
This function iterates over all the possible edges and asks user if they want the edge to exsist or not
parameters : void
Returns : void
*/
void Graph ::add_edge()
{
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = i; j < no_of_vertices; j++)
        {
            if (i != j)
            {
                char choice;
                cout << "Are vertices " << i << " and " << j << " adjacent? (Y/N) : ";
                cin >> choice;

                if (toupper(choice) == 'Y')
                {
                    int cost;
                    cout << "Please enter the cost of edge : ";
                    cin >> cost;
                    adj_matrix[i][j] = cost;
                    no_of_edges++;
                }
            }
        }
    }
}
// end of function

void Graph ::kruskals()
{
    int explored_vertices[no_of_vertices];
    int explored_index = 0;
    bool flag_1 = 0 ;
    bool flag_2 = 0 ;

    while (no_of_edges--)
    {
        int min = -1;
        int temp_i = 0, temp_j = 0;
        for (int i = 0; i < no_of_vertices; i++)
        {
            for (int j = 0; j < no_of_vertices; j++)
            {
                if (adj_matrix[i][j] > 0)
                {
                    if (min == -1)
                    {
                        min = adj_matrix[i][j];
                        temp_i = i;
                        temp_j = j;
                    }
                    else if (adj_matrix[i][j] <= min)
                    {
                        min = adj_matrix[i][j];
                        temp_i = i;
                        temp_j = j;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        for (int l = 2; l > 0; l--)
        {
            for (int k = 0; k < explored_index; k++)
            {
                if (explored_vertices[k] == temp_i )
                {
                    flag_1 = 1 ;
                    break ;
                }
            }              
        }

        for (int l = 2; l > 0; l--)
        {
            for (int k = 0; k < explored_index; k++)
            {
                if (explored_vertices[k] == temp_j )
                {
                    flag_2 = 1 ;
                    break ;
                }
            }
                
        }

        if (flag_1 == 1 && flag_2 == 1)
        {
            continue ;
        }
        else
        {
            flag_1 = flag_2 = 0 ;
            adj_matrix[temp_i][temp_j] = 0;
            explored_vertices[explored_index++] = temp_i;
            explored_vertices[explored_index++] = temp_j;
            cout << "Minimum edge available is between " <<temp_i << " and " << temp_j << " of cost : " << min << endl ;
        }
    }
}
// main function starts here
int main()
{
    Graph g;
    int no_of_vertices, no_of_edges;
    cout << "Enter the number of vertices : ";
    cin >> no_of_vertices;

    g.make_graph(no_of_vertices);
    g.add_edge();
    g.display();
    g.kruskals();

    return 0;
}
// end of main