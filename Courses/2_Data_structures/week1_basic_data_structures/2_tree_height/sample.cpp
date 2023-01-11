#include <iostream>

using namespace std;

class Tree
{
    struct node
    {
        int data;
        struct node *left = NULL;
        struct node *right = NULL;
    };

public:
    struct node *root = NULL; // The pointer to the staring node . for now this is null and will point to the root node when created
    struct node *temp = NULL; 
    void insert(struct node *&node, int element);
    void main_insert(struct node *&node, int element);
};

void Tree ::insert(struct node *&node, int element)
{
    if (node == NULL) // if there is no root node i.e. the tree is empty
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node)); 
        node = temp;
        node->data = element;
        node->left = NULL;
        node->right = NULL; 
    }
    else if (node->left == NULL) 
    {
        insert(node->left , element);
    }
    else if (node->right == NULL)
    {
        insert(node->right , element);
    }
    else
    {
        cout << "ERROR\n" ;
    }
}

void Tree :: main_insert(struct node *&node, int element)
{
}

int main()
{
    Tree t;

    int n , root_element ;
    cin >> n;

    int parent[n]; // This is the parent array to keep track for all the parents of a node

    for (int i = 0; i < n; i++)
    {
        cin >> parent[i];
        if (parent[i] == -1) 
        {
            root_element = i ;
        }
    }

    t.insert(t.root , root_element) ;

    for (int i = 0; i < n; i++)
    {
        if (parent[i] == root_element ) 
        {
        }
    }
}
