/*In this program, we perform traversals on Binary sreach tree recursively
Note :-
1)The BST is not a balanced tree
2) All the traversals take o(n) time complexity
3) Insertion takes o(log(n)) time averagely, since this is not a balanced BST.
*/
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
    void insert(struct node *&node, int element);
    int get_height(struct node *root);
    int max(int a, int b);
};

void Tree ::insert(struct node *&node, int element)
{
    if (node == NULL) // if there is no root node i.e. the tree is empty
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node)); // creating a memory in heap consisting a node
        node = temp;
        node->data = element;
        node->left = NULL;
        node->right = NULL; // here we create a new node
    }
    else if (element > node->data) // insert in right tree
    {
        insert(node->right, element);
    }
    else // insert in left tree
    {
        insert(node->left, element);
    }
}

int Tree ::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int Tree ::get_height(struct node *root)
{
    // cout << root->data << endl;
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        return 1 + max(get_height(root->left), get_height(root->right));
    }
}

int main()
{
    Tree t;

    /*insertion*/
    t.insert(t.root, 15);
    t.insert(t.root, 5);
    t.insert(t.root, 2);
    t.insert(t.root, 40);
    t.insert(t.root, 80);
    t.insert(t.root, 20);
    t.insert(t.root, 1);
    t.insert(t.root, 3);

    int h = t.get_height(t.root);
    cout << h;
}
