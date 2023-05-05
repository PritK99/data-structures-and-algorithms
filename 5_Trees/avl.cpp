/***************************************
    @brief        Implementing AVL trees
****************************************/
#include <iostream>
#include <math.h>

using namespace std;

class Tree
{
    struct node
    {
        int data;
        int height;
        struct node *parent = NULL;
        struct node *left = NULL;
        struct node *right = NULL;
    };
    void insert(int element);
    struct node *find(struct node *&node, int key);
    void rebalance(struct node *&node) ;
    void rebalanceRight(struct node *&node) ;
    void rebalanceLeft(struct node *&node) ;

public:
    struct node *root = NULL; // The pointer to the root node.
    void AVLinsert(int element);
    void adjustHeight(struct node *&node) ;
    void preorder(struct node *&node);
};

void Tree::adjustHeight(struct node *&node)
{
    struct node* p = node->parent ;
    int left = 0, right = 0;

    if (node->left != NULL)
    {
        left = node->left->height ;
    }
    if (node->right != NULL)
    {
        left = node->right->height ;
    }

    node->height = 1+ max(left, right) ;

    if (p != NULL)
    {
        adjustHeight(p) ;
    }

}

void Tree::rebalanceRight(struct node *&node) 
{
    struct node * l = node->left ;

    if (l->left->height < l->right->height)
    {
        
    }
}

void Tree::rebalanceLeft(struct node *&node) 
{
    // cout << "Rebalance right"<< endl ;
}

void Tree::AVLinsert(int element) 
{
    insert(element) ;
    struct node* x = find(root, element) ;
    rebalance(x) ;
}

void Tree::rebalance(struct node *&node)
{
    struct node* p = node->parent ;
    int left = 0, right = 0;

    if (node->left != NULL)
    {
        left = node->left->height ;
    }
    if (node->right != NULL)
    {
        right = node->right->height ;
    }

    if (left > right+1)
    {
        rebalanceRight(node) ;
    }
    else if (right > left+1)
    {
        rebalanceLeft(node) ;
    }

    adjustHeight(node) ;

    if (p != NULL)
    {
        rebalance(p) ;
    }
}

struct Tree::node *Tree::find(struct node *&node, int key)
{
    if (node != NULL)
    {
        if (key == node->data)
        {
            return node;
        }
        else if (key > node->data)
        {
            return find(node->right, key);
        }
        else
        {
            return find(node->left, key);
        }
    }
    return NULL;
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

void Tree::preorder(struct node *&node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

int main()
{
    Tree t;
    int x;

    // Insertion
    t.AVLinsert(15);
    t.AVLinsert(33);
    t.AVLinsert(45);
    t.AVLinsert(34);
    t.AVLinsert(1);
    t.AVLinsert(35);

    t.preorder(t.root) ;

    return 0;
}

