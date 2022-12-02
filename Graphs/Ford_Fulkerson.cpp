/*
INCOMPLETE
Given a flow network G with source s and sink t, the maximum flow problem is an optimization problem to find a flow of maximum value from s to t. Flow network G=(V, E), is essentially just a directed graph where each edge has a nonnegative flow capacity.
*/
#include <iostream>

using namespace std;

class Graph
{
private:
    int no_of_vertices;
    int **adj_matrix;
    int visited_arr;
    int path_index ;

public:
    int source;
    int sink;
    void make_graph(int no_of_vertices);
    void display();
    void add_edge();
    void identify_node();
    void get_path(int source, int sink);
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
        for (int j = 0; j < no_of_vertices; j++)
        {
            if (i != j)
            {
                char choice;
                cout << "Are vertices " << i << " and " << j << " adjacent? (Y/N) : ";
                cin >> choice;

                if (toupper(choice) == 'Y')
                {
                    int capacity;
                    cout << "Please enter the capacity of the edge : ";
                    cin >> capacity;
                    adj_matrix[i][j] = capacity;
                }
            }
        }
    }
}
// end of function

/*
This function simply tells us which node in given graph is the source and which is sink
parameters : void
Returns : void
*/
void Graph ::identify_node()
{
    // given a adj_matrix , we can get the source by finding the columns full of 0 and sink by finding rows full of 0
    bool flag = 0;
    for (int i = 0; i < no_of_vertices; i++)
    {
        for (int j = 0; j < no_of_vertices; j++)
        {
            if (adj_matrix[i][j] > 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            sink = i;
            break;
        }
        flag = 0;
    }
    flag = 0;
    for (int j = 0; j < no_of_vertices; j++)
    {
        for (int i = 0; i < no_of_vertices; i++)
        {
            if (adj_matrix[i][j] > 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            source = j;
            break;
        }
        flag = 0;
    }

    cout << "source Node : " << source << "\n";
    cout << "sink Node : " << sink << "\n";
}
// end of function

/*
This function finds path between 2 given nodes
parameters : void
Returns : void
*/
void Graph ::get_path(int source, int sink)
{
    int i = source;
    int j = sink;

    if (i != j)
    {
        for (int k = 0; k < no_of_vertices; k++)
        {
            if (adj_matrix[k] > 0)
            {
                for (int l = 0 ; l < path_index ; l++)
                {
                    if (k == visited_arr[l]) 
                    {
                        continue ;
                    }
                }
                get_path(adj_matrix[i][k], sink) ;
            }
            else
            {
                return;
            }
        }
    }
}

// main function starts here
int main()
{
    Graph g;
    int no_of_vertices;
    cout << "Enter the number of vertices : ";
    cin >> no_of_vertices;

    g.make_graph(no_of_vertices);
    g.add_edge();
    g.display();
    g.identify_node();
    // to get path, we originally pass our true source and sink
    g.get_path(g.source, g.sink);

    return 0;
}
// end of main