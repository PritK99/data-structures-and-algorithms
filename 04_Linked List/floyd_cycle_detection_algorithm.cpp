#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    public: 
    Node* head = NULL;
    void insert(int data);      //To insert data at the end of linked list
    void insert(Node* node);        //To point at an existing node 
    void print();
    void detect_cycle();
    void remove(int data);
};

void LinkedList::insert(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new Node(data);
    }
}

void LinkedList::insert(Node* node)
{
    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void LinkedList::print()
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void LinkedList::detect_cycle()
{
    Node* slow = head;
    Node* fast = head;

    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        do
        {
            if (fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                slow=slow->next;
            }
            else
            {
                cout << "No Cycle Detected";
                return;
            }
        } while (slow != fast);
        
        fast = head;

        while (slow != fast)
        {
            slow=slow->next;
            fast=fast->next;
        } 

        cout << "Cycle detected at: " << slow->data << endl;
    }
}

void LinkedList::remove(int key)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else if(head->data == key)
    {
        Node* temp = head;
        temp = head->next;
        free(head);
        head = temp;
    }
    else
    {
        bool flag = 0;
        Node* temp = head;
        while (temp->next != NULL)
        {
            if (temp->next->data == key)
            {
                flag = 1;
                Node* p = temp->next;
                temp->next = temp->next->next;
                free(p);
                break;
            }
            else
            {
                temp = temp->next;
            }            
        }
        if (flag == 0)
        {
            cout << "Key Not Found" << endl;
        }
    }
}

int main()
{
    LinkedList L1;
    L1.insert(3);
    L1.insert(6);
    L1.insert(9);
    L1.insert(12);
    Node* p = L1.head->next;
    L1.insert(p);        //Creating a cycle in linked list
    L1.detect_cycle();
    LinkedList L2;
    L2.insert(5);
    L2.insert(10);
    L2.detect_cycle();
    return 0;
}