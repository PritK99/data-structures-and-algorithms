/*In this program, we perform traversals on Binary sreach tree but with a non-recursive approach
Note :-
1)The BST is not a balanced tree 
2) All the traversals take o(n) time complexity and make use of stack
3) Insertion takes o(log(n)) time averagely, since this is not a BST. 
*/
#include <iostream>

using namespace std;

void insert(struct node *&node, int element);
void inorder(struct node* root) ;
void preorder(struct node* root) ;
void postorder(struct node* root) ;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL; // The pointer to the staring node . for now this is null and will point to the root node when created

int main()
{
    /*insertion*/
    insert(root, 15);
    insert(root, 5);
    insert(root , 2) ;
    insert(root , 40) ;
    insert(root , 80) ;
    insert(root , 20) ;
    insert(root , 1) ;
    insert(root , 3) ;

    /*traversing*/
    cout << "The inorder Traversal is : " ;
    inorder(root) ;
    cout << "\n" ;
    cout << "The preorder Traversal is : " ;
    preorder(root) ;
    cout << "\n" ;
    cout << "The postorder Traversal is : " ;
    postorder(root) ;
    cout << "\n" ;
}

void insert(struct node * &node, int element)
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

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
