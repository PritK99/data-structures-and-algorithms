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
        struct node *parent = NULL ;
        struct node *left = NULL;
        struct node *right = NULL;
    };

public:
    struct node *root = NULL; // The pointer to the staring node . for now this is null and will point to the root node when created
    void insert(struct node *&node, int element);
    void display(struct node *&node);
    void remove(struct node *&node, int element);
    int find(struct node *&node, int key);
    // int next(struct node *&node, int key);
    int leftDescendant(struct node *&node);
    // int RightAncestors(struct node *&node);
};

int Tree::leftDescendant(struct node *&node)
{
    if (node->left == NULL)
    {
        return node->data;
    }
    return leftDescendant(node->left);
}

// int Tree::RightAncestors(struct node *&node)
// {
// }

// int Tree::next(struct node *&node, int key)
// {
//     if (node != NULL)
//     {
//         if (key == node->data)
//         {
//             if (node->right != NULL)
//             {
//                 leftDescendant(node->right);
//             }
//             else
//             {
//                 // rightancestors
//             }
//             return 0;
//         }
//         else if (key > node->data)
//         {
//             int x = find(node->right, key);
//             if (x == 0)
//             {
//                 return 0;
//             }
//         }
//         else
//         {
//             int x = find(node->left, key);
//             if (x == 0)
//             {
//                 return 0;
//             }
//         }
//     }
//     return 1;
// }

int Tree ::find(struct node *&node, int key)
{
    if (node != NULL)
    {
        cout << node->data << " -> ";
        if (key == node->data)
        {
            return 0;
        }
        else if (key > node->data)
        {
            int x = find(node->right, key);
            if (x == 0)
            {
                return 0;
            }
        }
        else
        {
            int x = find(node->left, key);
            if (x == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

void Tree ::display(struct node *&node)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

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

void Tree ::remove(struct node *&node, int element)
{
    cout << "Pending" << endl;
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

    // int x = t.find(t.root, 20);
    // if (x == 0)
    // {
    //     cout << "Key found\n";
    // }
    // else
    // {
    //     cout << "Key not found\n";
    // }

    int x = t.leftDescendant(t.root->right->right) ;
    cout << x << endl ;

    return 0;
}
