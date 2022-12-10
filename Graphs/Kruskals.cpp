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
    /* Initializing a array to keep a record of families of each vertex
    index 0 of array means 0th vertex and so on*/
    int sets[no_of_vertices];
    int total_cost = 0;
    for (int i = 0; i < no_of_vertices; i++)
    {
        sets[i] = i; // This step makes all the vertices a parent of themselves
    }

    cout << "The edges which belong to MST are :" ;

    while (no_of_edges--)
    {
        /*we run the while loop for the total no of edges*/

        /*First we check if the MST is complete*/
        bool not_completed_flag = 0;
        for (int i = 1; i < no_of_vertices; i++)
        {
            if (sets[i - 1] != sets[i])
            {
                not_completed_flag = 1; // All the vertices are still not connected in MST
                break;
            }
        }

        if (not_completed_flag == 0)
        {
            break; // this means MST has been created completely
        }
        else
        {
            /*first we find the edge with the minimum weight*/
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
            /*Now that we have the most minimum edge possible, we check if that belongs to the same family or not*/
            /*we store the values in temp_1 and temp_2 since sets[temp_i] OR sets[temp_j] are subject to change after each pass in for loop*/
            int temp_1 = sets[temp_i] ;
            int temp_2 = sets[temp_j] ;
            if (sets[temp_i] != sets[temp_j])
            {
                for (int i = 0; i < no_of_vertices; i++)
                {
                    /*Convert the entire family of second vertex to first family*/
                    if (sets[i] == temp_2)
                    {
                        sets[i] = temp_1 ;
                    }
                }
                total_cost = total_cost + adj_matrix[temp_i][temp_j];

                cout << " " << temp_i << "-" << temp_j ;
            }

            adj_matrix[temp_i][temp_j] = 0; // we have made cost of that path 0 to avoid recomparison

        }
    }


    cout << "\nTotal cost of the MST : : " << total_cost << endl;
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