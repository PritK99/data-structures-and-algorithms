/***************************************************************
    @brief        Implementing binary trees and basic operations
****************************************************************/
#include <iostream>

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
    int next(struct node *&node, int key);
    int leftDescendant(struct node *&node);
    // int RightAncestors(struct node *&node);
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

int Tree :: next(struct node *&node, int key)
{
    int x ;
    if (node->right != NULL)
    {
        x = leftDescendant(node->right) ;
    }
    else
    {
        cout << "SORRY!\n" ;
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

    //Insertion
    t.insert(15);
    t.insert(13);
    t.insert(5);
    t.insert(34);
    t.insert(1);

    //Finding the element
    // bool x = t.find(t.root, 131);
    // if (x == 1)
    // {
    //     cout << "found\n";
    // }
    // else
    // {
    //     cout << "Element not found\n";
    // }

    //Inorder traversal
    // t.inorder(t.root) ;

    //Deletion
    int x = t.next(t.root, 5) ;
    cout << x << endl;

    //Inorder traversal
    t.inorder(t.root) ;

    return 0;
}
