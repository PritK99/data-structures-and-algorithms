/***************************************************
    @brief        Finding the height of a given tree
****************************************************/
#include <iostream>
#include <algorithm>

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

/*
 * Function Name: insert
 * Input: a pointer to root node and the element to be inserted
 * Output: None
 * Logic: Inserts a node in the binary tree
 * Example Call: insert(root, 5)
 */
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

/*
 * Function Name: get_height
 * Input: a pointer to root node 
 * Output: Returns the height of tree
 * Example Call: get_height(root)
 */
int Tree ::get_height(struct node *root)
{
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
    Tree t;     //Create an object t of Tree

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
/*
Analysis: The above algorithm runs in O(n) for finding height and O(nlog(n)) for insertion
*/
