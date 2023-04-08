/***************************************************************
    @brief        Implementing binary trees and basic operations
****************************************************************/
#include <iostream>
#include <math.h>

using namespace std;

class Tree
{
    struct node
    {
        int data;
        struct node *parent = NULL;
        struct node *left = NULL;
        struct node *right = NULL;
    };

public:
    struct node *root = NULL; // The pointer to the root node.
    void insert(int element);
    void inorder(struct node *&node);
    // void remove(struct node *&node, int element);
    bool find(struct node *&node, int key);
    int next(struct node *node, int key);
    int leftDescendant(struct node *&node);
    int RightAncestors(struct node *&node);
    void range(struct node *node, int lower, int upper);
    void nearestNeighbour(struct node *node, int key) ;
};
void Tree::inorder(struct node *&node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int Tree :: next(struct node *node, int key)
{
    //Traverse to key node
    while (node->data != key)
    {
        if (node->data > key)
        {
            node = node->left ;
        }
        else
        {
            node = node-> right ;
        }
    }

    //Next element is either a left descendant of right child node or an ancestor with greater value than node.
    int x ;
    if (node->right != NULL)
    {
        x = leftDescendant(node->right) ;
    }
    else
    {
        x = RightAncestors(node) ;
    }

    return x ;
}

int Tree::leftDescendant(struct node *&node)
{
    if (node->left == NULL)
    {
        return node->data ;
    }
    return leftDescendant(node->left);
}

int Tree::RightAncestors(struct node *&node)
{
    if (node->parent != NULL)
    {
        if (node->data < node->parent->data)
        {
            return node->parent->data ;
        }
        return RightAncestors(node->parent) ;
    }
    return -1 ;
}

void Tree::range(struct node *node, int lower, int upper)
{
    cout << "The elements which lie in given range are: " ;

    //Traversing to the nearest element
    while (node->data != lower)
    {
        if (node->data > lower)
        {
            if (node->left == NULL)
            {
                break ;
            }
            node = node->left ;
        }
        else
        {
            if (node->right == NULL)
            {
                break ;
            }
            node = node-> right ;
        }
    }

    //Printing all elements which lie in range
    int x = node->data ;

    while (x < upper && x != -1)
    {
        cout << x << " " ;
        x = next(root, x) ;
    }

    cout << endl ;
}

void Tree::nearestNeighbour(struct node *node, int key) 
{
    //Traversing to the nearest element
    while (node->data != key)
    {
        if (node->data > key)
        {
            if (node->left == NULL)
            {
                break ;
            }
            node = node->left ;
        }
        else
        {
            if (node->right == NULL)
            {
                break ;
            }
            node = node-> right ;
        }
    }

    int a = INT_MAX, b =INT_MAX, c = INT_MAX ;
    if (node->parent != NULL)
    {
        a = fabs(key - node->parent->data) ;
    }
    if (node->left != NULL)
    {
        b = fabs(key - node->left->data) ;
    }
    if (node->right != NULL)
    {
        c = fabs(key - node->right->data) ;
    }

    cout << "The nearest neighbour to given element is: " ;

    int min = 0;

    if (a < b && a < c)
    {
        cout << node->parent->data ;
    }
    else if (b < c)
    {
        cout << node->left->data ;
    }
    else
    {
        cout << node->right->data ;
    }

    cout << endl ;
}

bool Tree ::find(struct node *&node, int key)
{
    if (node != NULL)
    {
        cout << node->data << " -> ";
        if (key == node->data)
        {
            return true;
        }
        else if (key > node->data)
        {
            int x = find(node->right, key);
            if (x == 0)
            {
                return true;
            }
        }
        else
        {
            int x = find(node->left, key);
            if (x == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void Tree::insert(int element)
{
    if (root == NULL)
    {
        // Special case for root node
        root = (struct node *)malloc(sizeof(node));
        root->data = element;
        root->parent = NULL;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        struct node *node = root; // Creating a traversing pointer
        bool inserted = 0;
        while (!inserted)
        {
            if (element > node->data)
            {
                if (node->right == NULL)
                {
                    node->right = (struct node *)malloc(sizeof(struct node));
                    node->right->parent = node;
                    node->right->data = element;
                    node->right->left = NULL;
                    node->right->right = NULL;
                    inserted = 1;
                    continue;
                }
                else
                {
                    node = node->right;
                }
            }
            else
            {
                if (node->left == NULL)
                {
                    node->left = (struct node *)malloc(sizeof(struct node));
                    node->left->parent = node;
                    node->left->data = element;
                    node->left->left = NULL;
                    node->left->right = NULL;
                    inserted = 1;
                    continue;
                }
                else
                {
                    node = node->left;
                }
            }
        }
    }
}

int main()
{
    Tree t;
    int x ;

    //Insertion
    t.insert(15);
    t.insert(13);
    t.insert(5);
    t.insert(34);
    t.insert(1);

    //Finding the element
    x = t.find(t.root, 131);
    if (x == 1)
    {
        cout << "found\n";
    }
    else
    {
        cout << "Element not found\n";
    }

    //Inorder traversal
    t.inorder(t.root) ;

    //Next element
    x = t.next(t.root, 5) ;
    cout << x << endl;

    //Range 
    t.range(t.root, 1, 33) ;

    //Nearest neighbour
    t.nearestNeighbour(t.root, 12) ;

    return 0;
}
