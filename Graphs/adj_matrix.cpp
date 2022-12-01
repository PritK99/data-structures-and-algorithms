/*
Code to create a graph using Adjacency Matrix representation
We consider the graph to be directed graph and non-weighted with no self loops
*/
#include <iostream>

using namespace std;

class Graph
{
private:
    int no_of_vertices;
    bool **adj_matrix;

public:
    void make_graph(int no_of_vertices);
    void display();
    void add_edge();
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
    adj_matrix = new bool *[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adj_matrix[i] = new bool[no_of_vertices];
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
                    adj_matrix[i][j] = 1;
                }
            }
        }
    }
}
// end of function

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

    return 0;
}
// end of main

/*referance
class Graph {
    private:
    bool** adjMatrix;
    int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void display() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  ~Graph() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }
};

int main() {
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.display();
}
*/