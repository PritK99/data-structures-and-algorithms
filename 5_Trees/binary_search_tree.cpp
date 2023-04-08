/**********************************************************************
    @brief        Implementing binary search trees and basic operations
***********************************************************************/
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
    int next(struct node *node, int key);
    int leftDescendant(struct node *&node);
    int RightAncestors(struct node *&node);
    void remove(struct node *node, int element);
    bool find(struct node *&node, int key);
    void range(struct node *node, int lower, int upper);
    void nearestNeighbour(struct node *node, int key);
    void inorder(struct node *&node);
};

/*
 * Function Name: insert
 * Input: The element to be inserted
 * Output: None
 * Logic: Inserts a node in the binary tree
 * Example Call: insert(5)
 */
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

/*
 * Function Name: next
 * Input: The root pointer and element to be inserted
 * Output: None
 * Logic: Finds the next element in inorder traversal
 * Example Call: next(root, 5)
 */
int Tree ::next(struct node *node, int key)
{
    // Traverse to key node
    while (node->data != key)
    {
        if (node->data > key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    // Next element is either a left descendant of right child node or an ancestor with greater value than node.
    int x;
    if (node->right != NULL)
    {
        x = leftDescendant(node->right);
    }
    else
    {
        x = RightAncestors(node);
    }

    return x;
}

/*
 * Function Name: leftDescendant
 * Input: Pointer to the node
 * Output: Returns the value of left most descendent of the given node
 * Example Call: leftDescendant(root->right)
 */
int Tree::leftDescendant(struct node *&node)
{
    while (node->left != NULL)
    {
        node = node->left ;
    }

    return node->data ;
}

/*
 * Function Name: RightAncestors
 * Input: Pointer to the node
 * Output: Returns the value of right ancestor with value greater than that of the given node
 * Example Call: RightAncestors(root->right)
 */
int Tree::RightAncestors(struct node *&node)
{
    if (node->parent != NULL)
    {
        if (node->data < node->parent->data)
        {
            return node->parent->data;
        }
        return RightAncestors(node->parent);
    }
    return -1;
}

/*
 * Function Name: range
 * Input: Pointer to the node, integer values of upper limit and lower limit of range.
 * Output: Prints the elements of tree lying in the range
 * Example Call: range(root, 8, 45)
 */
void Tree::range(struct node *node, int lower, int upper)
{
    cout << "The elements which lie in given range are: ";

    // Traversing to the nearest element
    while (node->data != lower)
    {
        if (node->data > lower)
        {
            if (node->left == NULL)
            {
                break;
            }
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
            {
                break;
            }
            node = node->right;
        }
    }

    // Printing all elements which lie in range
    int x = node->data;

    while (x < upper && x != -1)
    {
        cout << x << " ";
        x = next(root, x);
    }

    cout << endl;
}

/*
 * Function Name: nearestNeighbour
 * Input: Pointer to the node, integer value of key
 * Output: Prints the element in tree which is nearest to the given key
 * Example Call: nearestNeighbour(root, 5)
 */
void Tree::nearestNeighbour(struct node *node, int key)
{
    // Traversing to the nearest element
    while (node->data != key)
    {
        if (node->data > key)
        {
            if (node->left == NULL)
            {
                break;
            }
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
            {
                break;
            }
            node = node->right;
        }
    }

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (node->parent != NULL)
    {
        a = fabs(key - node->parent->data);
    }
    if (node->left != NULL)
    {
        b = fabs(key - node->left->data);
    }
    if (node->right != NULL)
    {
        c = fabs(key - node->right->data);
    }

    cout << "The nearest neighbour to given element is: ";

    int min = 0;

    if (a < b && a < c)
    {
        cout << node->parent->data;
    }
    else if (b < c)
    {
        cout << node->left->data;
    }
    else
    {
        cout << node->right->data;
    }

    cout << endl;
}

/*
 * Function Name: remove
 * Input: Pointer to the node, integer value of element
 * Output: Deletes the node with the given element as value
 * Example Call: remove(root, 7)
 */
void Tree::remove(struct node *node, int element)
{
    // Traversing to the element
    while (node->data != element)
    {
        if (node->data > element)
        {
            if (node->left == NULL)
            {
                return;
            }
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
            {
                return;
            }
            node = node->right;
        }
    }

    // Leaf node
    if (node->left == NULL && node->right == NULL)
    {
        if (node->parent->left != NULL && node->parent->left->data == element)
        {
            node->parent->left = NULL;
            free(node);
        }
        else
        {
            node->parent->right = NULL;
            free(node);
        }
    }
    // Node with right subtree
    else if (node->right != NULL)
    {
        struct node *temp = node->right;

        while (temp->left != NULL)
        {
            temp = temp->left;
        }

        node->data = temp->data;

        if (temp->right != NULL)
        {
            if (temp->parent == node)
            {
                node->right = temp->right;
                temp->right->parent = node;
            }
            else
            {
                temp->parent->left = temp->right;
                temp->right->parent = temp->parent;
            }
        }

        if (temp == node->right)
        {
            node->right = NULL;
        }

        free(temp);
    }
    // Node with a left subtree only
    else
    {

        if (node->left != NULL)
        {
            node->parent->left = node->left;
            node->left->parent = node->parent;
        }
        free(node);
    }
}

/*
 * Function Name: find
 * Input: a pointer to root node and integer value of key
 * Output: Returns true, if the key belongs to tree
 * Example Call: find(root, 4)
 */
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

/*
 * Function Name: inorder
 * Input: a pointer to root node
 * Output: Prints inorder traversal of tree
 * Example Call: inorder(root)
 */
void Tree::inorder(struct node *&node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int main()
{
    Tree t;
    int x;

    // Insertion
    t.insert(15);
    t.insert(13);
    t.insert(5);
    t.insert(34);
    t.insert(1);
    t.insert(35);

    // //Finding the element
    x = t.find(t.root, 131);
    if (x == 1)
    {
        cout << "found\n";
    }
    else
    {
        cout << "Element not found\n";
    }

    // //Inorder traversal
    t.inorder(t.root);

    // //Next element
    x = t.next(t.root, 5);
    cout << x << endl;

    // //Range
    t.range(t.root, 1, 33);

    // //Nearest neighbour
    t.nearestNeighbour(t.root, 12);

    // Deleting element
    t.remove(t.root, 5);

    // Inorder traversal
    t.inorder(t.root);

    return 0;
}
/*
Analysis: Time Complexity of all the operations which includes insertion, deletion, find, range, leftDescendant, rightAncestor, nearestNeighbour, next, inorder take O(nlog(n)) time complexity.
*/
