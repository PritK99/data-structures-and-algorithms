#include <iostream>

using namespace std;

#define VERTICES 100

void enqueue(int element);
void display();
int dequeue();

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

public:
    bool visited[VERTICES] = {0};
    void make_graph(int no_of_vertices);
    void display();
    void add_edge();
    void bfs(int v);
};

struct Queue
{
    int data;
    class Queue *next; // next is a pointer of type Queue which points towards the next Queue
};
/*initially both the pointers are NULL*/
struct Queue *front = NULL;
struct Queue *rear = NULL;

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
                        adj_list[i] = new struct Node;
                        adj_list[i]->data = j;
                        adj_list[i]->next = NULL;
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

void Graph ::bfs(int v)
{
    visited[v] = 1;
    cout << v << " ";

    enqueue(v);

    while (front != NULL)
    {
        int u = dequeue();

        struct Node *temp;
        temp = adj_list[u];

        while (temp != NULL)
        {
            if (visited[temp->data] == 0)
            {
                visited[temp->data] = 1;
                enqueue(temp->data);
                cout << temp->data << " " ;
            }
            temp = temp->next;
        }
    }
}
// end of function

void Graph ::make_graph(int no_of_vertices)
{
    this->no_of_vertices = no_of_vertices;
    // creating a graph
    adj_list = new struct Node *[no_of_vertices];
    for (int i = 0; i < no_of_vertices; i++)
    {
        adj_list[i] = NULL;
    }
}
// end of function

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
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << temp->data;
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

    for (int v = 0; v < no_of_vertices; v++)
    {
        if (g.visited[v] == 0)
        {
            g.bfs(v);
        }
    }

    return 0;
}
// end of main

void enqueue(int element)
{
    Queue *temp = (Queue *)malloc(sizeof(Queue)); // dynaminc allocation of memory
    if (temp == NULL)
    {
        cout << "Queue is full";
    }
    else if (front == NULL) // or rear == NULL, both conditions work
    {
        front = rear = temp;
        temp->data = element;
        temp->next = NULL;
    }
    else
    {
        rear->next = temp; // the next of the last / rear Queue should point at new Queue temp
        temp->data = element;
        temp->next = NULL;
        rear = temp; // rear should point to the new Queue formed
    }
}

int dequeue()
{
    if (front == NULL)
    {
        return -1;
    }
    else
    {
        int x = front->data;

        Queue *temp = front;
        front = front->next;
        delete temp; // Deallocating the memory given to Queue

        return x;
    }
}

void display()
{
    Queue *temp = front;
    if (front == NULL)
    {
        cout << "Queue is empty!";
    }
    else if (front == rear) // incase of only one element in queue
    {
        cout << "The elements in queue are : " << front->data;
        struct Queue *front = NULL;
        struct Queue *rear = NULL;
    }
    else
    {
        cout << "The elements in queue are : ";
        while (temp != NULL)
        {
            cout << temp->data << " "; // prints data in all Queues
            temp = temp->next;
        }
    }

    cout << "\n";
}