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
    struct node *root = NULL;   // The pointer to the root node. 
    void insert(int element);
    void inorder(struct node *&node);
    // void remove(struct node *&node, int element);
    // int find(struct node *&node, int key);
    // int next(struct node *&node, int key);
    // int leftDescendant(struct node *&node);
    // int RightAncestors(struct node *&node);
};

void Tree::inorder(struct node *&node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " " ;
        inorder(node->right);
    }
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
        struct node *node = root;  //Creating a traversing pointer
        bool inserted = 0;
        while (!inserted)
        {
            if (element > node->data)
            {
                if (node->right == NULL)
                {
                    node->right = (struct node *)malloc(sizeof(node));
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
                    node->left = (struct node *)malloc(sizeof(node));
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
    t.insert(15);
    t.insert(13);
    t.insert(5);
    t.insert(34);
    t.insert(1);

    t.inorder(t.root) ;

    return 0;
}
