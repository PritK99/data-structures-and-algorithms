/********************************************************************
    @brief        Implementing binary trees and performing traversals
*********************************************************************/
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
    void inorder(struct node *root);
    void preorder(struct node *root);
    void postorder(struct node *root);
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
 * Function Name: inorder
 * Input: a pointer to root node
 * Output: Prints inorder traversal of tree
 * Example Call: inorder(root)
 */
void Tree ::inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/*
 * Function Name: preorder
 * Input: a pointer to root node
 * Output: Prints preorder traversal of tree
 * Example Call: preorder(root)
 */
void Tree ::preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/*
 * Function Name: postorder
 * Input: a pointer to root node
 * Output: Prints postorder traversal of tree
 * Example Call: postorder(root)
 */
void Tree ::postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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

    /*traversing*/
    printf("The inorder Traversal is : ");
    t.inorder(t.root);
    printf("\n");
    printf("The preorder Traversal is : ");
    t.preorder(t.root);
    printf("\n");
    printf("The postorder Traversal is : ");
    t.postorder(t.root);
    printf("\n");
}
/*
Analysis: The above algorithm runs in O(n) for traversal and O(nlog(n)) for insertion
*/
