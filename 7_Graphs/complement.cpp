/*
INCOMPLETE
In this program, we will take the complement of given graph using linked list
for complement using adjacency matrix , we simply run two for loops and convert all 0's to 1's and vice versa 
*/

#include <iostream>

using namespace std;

class Graph
{
private:
    struct Node
    {
        int data;
        struct Node *next;
    };
    int no_of_vertices;
    struct Node **adj_list;
    struct Node **complement_adj_list;

public:
    void make_graph(int no_of_vertices);
    void display();
    void add_edge();
    void complement();
    void display_complement();
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
    adj_list = new struct Node *[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adj_list[i] = NULL;
    }

    complement_adj_list = new struct Node *[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        complement_adj_list[i] = NULL;
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
    cout << "The adjacency list representation is :-\n";
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << i << " : ";
        if (adj_list[i] != NULL)
        {
            struct Node *temp;
            temp = adj_list[i];
            while (temp->next != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << temp->data;
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
                    if (adj_list[i] == NULL)
                    {
                        struct Node *temp;
                        temp = new struct Node;
                        adj_list[i] = temp;
                        temp->data = j;
                        temp->next = NULL;
                        continue;
                    }
                    struct Node *temp;
                    temp = adj_list[i];
                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = new struct Node;
                    temp->next->data = j;
                    temp->next->next = NULL;
                }
            }
        }
    }
}
// end of function

void Graph ::complement()
{
    for (int i = 0; i < no_of_vertices; i++)
    {
        if (adj_list[i] == NULL)
        {
            complement_adj_list[i] = new struct Node;
            struct Node *temp = complement_adj_list[i];
            for (int k = 0; k < no_of_vertices; k++)
            {
                temp->data = k;
                temp->next = new struct Node;
                temp = temp->next;
            }
            temp->next = NULL;
            continue;
        }
        else
        {
            struct Node *temp = adj_list[i];
            int counter = 0;
            while (counter < no_of_vertices)
            {
                if (temp->next != NULL)
                {
                    cout << "if wala part" ;
                    if (counter == temp->data)
                    {
                        counter++;
                        temp = temp->next;
                    }
                    else
                    {
                        do
                        {
                            temp->data = counter;
                            temp->next = new struct Node;
                            temp = temp->next;
                            counter++;
                        } while (counter == temp->data);
                    }
                }
                else
                {
                    cout << "else wala part" ;
                    for (; counter < no_of_vertices; counter++)
                    {
                        temp->data = counter;
                        temp->next = new struct Node;
                        temp = temp->next;
                    }
                    temp->next = NULL;
                }
            }
        }
    }
}

/*
This function is used to display the graph
parameters : void
Returns : void
*/
void Graph ::display_complement()
{
    cout << "The adjacency list representation of the complemented graph is :-\n";
    for (int i = 0; i < no_of_vertices; i++)
    {
        cout << i << " : ";
        if (complement_adj_list[i] != NULL)
        {
            struct Node *temp;
            temp = complement_adj_list[i];
            while (temp->next != NULL)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL";
        }
        cout << "\n";
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
    g.complement();
    g.display_complement();
    return 0;
}
// end of main