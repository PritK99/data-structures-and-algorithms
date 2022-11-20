/*In this program, we perform traversals on Binary sreach tree but with a non-recursive approach
Note :-
1)The BST is not a balanced tree
2) All the traversals take o(n) time complexity and make use of stack
3) Insertion takes o(log(n)) time averagely, since this is not a BST.
*/
#include <iostream>
#define MAX_SIZE 100

using namespace std;

void insert(struct node *&node, int element);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void levelorder(struct node *root);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL; // The pointer to the staring node . for now this is null and will point to the root node when created

/**************Defining Members and methods for creating Stack***************/
class Stack
{
private:
    struct node *stack[MAX_SIZE];
    int top = -1;

public:
    void push(struct node *element);
    struct node *pop();
    struct node *peek();
};

/*This function allows us to insert an element in stack*/
void Stack ::push(struct node *element)
{
    if (top != MAX_SIZE - 1) // We can not push anymore elements if the stack is full
    {
        top++;
        stack[top] = element;
    }
}
// end of function

/*This function removes the topmost element of stack
if the function returns NULL , it implies stack is empty*/
struct node *Stack ::pop() // We can not pop any elements if the stack is empty
{
    if (top != -1)
    {
        return stack[top--];
        /* We need to do top-- above itself cause the staements below the return statement are not executed*/
    }
    else
    {
        return NULL;
    }
}
// end of function

/*This function simply returns the topmost element of stack without deleting it from the stack
if the function returns -1 , it implies stack is empty*/
struct node *Stack ::peek()
{
    if (top != -1)
    {
        return stack[top]; // here, we simply return the topmost element and not decrement top
    }
    else
    {
        return NULL;
    }
}
// end of function

/**************Defining Members and methods for creating Queue***************/
class Queue
{
private:
    struct node * queue[MAX_SIZE];
    struct node ** rear = NULL; 
    struct node ** front = NULL ; // initially , the pointers points to NULL

public:
    void enqueue(struct node * element);
    struct node * dequeue();
    bool isEmpty();
    bool isFull();
    void display();
    void new_init(struct node *root) ;
};

/* to insert an element to the queue*/
void Queue ::enqueue(struct node * element)
{
    if (!isFull()) //insert element only if queue is not full
    {
        if (rear == NULL) // if the queue is empty , and the element is first to be inserted
        {
            rear = queue; // points to the first element in queue
            front = queue;
            queue[0] = element;
        }
        else
        {
            rear++;          // increment the pointer to next position
            *rear = element; // change the value of next position
        }
    }
    else
    {
        cout << "queue is full!\n";
    }
}
// end of function

/* to insert an element to the queue*/
struct node * Queue ::dequeue()
{
    if (!isEmpty()) //we check if queue is not empty
    {
        return *front ;
        front++; // incrementing the front the pointer to previous position
        //for dequeue , we first delete the element to which the front is pointing , then we increment front
    }
    else
    {
        return NULL ;
    }
}
// end of function

/*to display the entire queue*/
void Queue ::display()
{
    if (!isEmpty())
    {
        cout << "The elements of queue are : ";
        for (int i = 0; front + i <= rear ; i++) // here , we print the element in queue till address of queue's last element matches with address at which rear points
        {
            cout << (*(front+i))->data << " " ;
        }
        cout << "\n";
    }
    else
    {
        cout << "The queue is empty!\n";
    }
}
// end of function

bool Queue ::isFull()
{
    if (rear >= &queue[MAX_SIZE - 1])
    {
        return true ; // we return false since the queue had 1 element left and is not yet empty
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}

// returns true if queue is empty. We generally use this function in dequeue() to check during deletion
bool Queue ::isEmpty()
{
    if (rear < front || rear == NULL) //when the queue is empty , ether the front pointer is ahead of the rear pointer , or the rear pointer is null
    {
        return true;
    }
    else
    {
        return false; // for all other cases , queue is not empty
    }
}
// end of function

void Queue ::new_init(struct node *root)
{
    cout << "vlue of rear at pos 1 is :" << *rear ;
    cout << "vlue of queue is :" << &queue[MAX_SIZE-1] ;

    if (!isEmpty())
    {
        root = *queue;
    }
    else
    {
        root = NULL;
    }
}

void insert(struct node *&node, int element)
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

void preorder(struct node *root)
{
    Stack s;
    while (1)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        }
        else if (s.peek() == NULL)
        {
            break;
        }
        else
        {
            root = s.pop();
            root = root->right;
        }
    }
}

void inorder(struct node *root)
{
    Stack s;
    while (1)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else if (s.peek() == NULL)
        {
            break;
        }
        else
        {
            root = s.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void levelorder(struct node *root)
{
    Queue q;

    if (root != NULL)
    {
        q.enqueue(root);
    }

    while (1)
    {
        if (root->left != NULL)
        {
            q.enqueue(root->left);
        }

        if (root->right != NULL)
        {
            q.enqueue(root->right);
        }

        q.new_init(root);

        if (root == NULL)
        {
            break;
        }
    }
}

int main()
{
    /*insertion*/
    insert(root, 15);
    insert(root, 5);
    insert(root, 2);
    insert(root, 40);
    insert(root, 80);
    insert(root, 20);
    insert(root, 1);
    insert(root, 3);

    /*traversing*/
    // cout << "The inorder Traversal is : ";
    // inorder(root);
    // cout << "\n";
    // cout << "The preorder Traversal is : ";
    // preorder(root);
    // cout << "\n";
    // cout << "The postorder Traversal is : " ;
    // postorder(root) ;
    // cout << "\n" ;
    cout << "The level-order Traversal is : ";
    levelorder(root);
    cout << "\n";
}
