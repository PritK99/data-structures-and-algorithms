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
    void insert(int data);
    void print();
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
    LinkedList L;
    L.insert(3);
    L.insert(6);
    L.insert(9);
    L.print();
    L.remove(9);
    L.print();
    return 0;
}