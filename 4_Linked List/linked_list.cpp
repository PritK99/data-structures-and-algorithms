/*
This program creates a linked list and preforms basic operations on it such as insertions of an element, deletion of an element etc.
Note : Without using the tail pointer, time complexity to insert an element is o(n). However, we can do this in o(1) by using a tail pointer
*/
#include <iostream>

using namespace std;

class LinkedList
{
    struct node
    {
        int data;
        struct node *next = NULL;
    };
    struct node *head = NULL;

public:
    void display();
    void insert(int key);
    void remove(int key);
};

void LinkedList ::display()
{

    struct node *temp = head;

    if (temp == NULL)
    {
        cout << "The list is empty\n";
    }
    else
    {
        cout << "Elements in linked list are : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}

void LinkedList ::insert(int key)
{
    if (head == NULL)
    {
        struct node *temp = new node;
        head = temp;
        temp->data = key;
        temp->next = NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node;
        temp = temp->next;
        temp->data = key;
        temp->next = NULL;
    }
}

void LinkedList ::remove(int key)
{
    int found = 0;

    if (head != NULL) // if LinkedList is not empty
    {
        struct node *temp = head;

        if (temp->data == key) // if the first element of list is to be deleted
        {
            head = temp->next;
            free(temp);
            found = 1;
        }

        if (temp->next != NULL)
        {
            while (temp->next->next != NULL && found == 0) // if the element to be deleted is not the first or last element in linked list
            {
                if (temp->next->data == key)
                {
                    struct node *p = temp->next;
                    temp->next = temp->next->next;
                    free(p);
                    found = 1;
                    break;
                }
                temp = temp->next;
            }

            if (temp->next->data == key && found == 0)
            {
                free(temp->next);
                found = 1;
                temp->next = NULL;
            }
        }

        if (found == 0)
        {
            cout << "Element not found\n";
        }
    }
}

int main()
{
    LinkedList l;

    // menu driven program
    int choice = 0, key;
    while (1)
    {
        cout << "Choose 1 to insert an element to the linked list\n";
        cout << "Choose 2 to delete an element from the linked list\n";
        cout << "Choose 3 to display the linked list\n";
        cout << "Choose 4 to exit\n";
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 4)
        {
            break;
        }
        else if (choice == 1)
        {
            cout << "Please enter the key element : ";
            cin >> key;
            l.insert(key);
        }
        else if (choice == 2)
        {
            cout << "Please enter the key element : ";
            cin >> key;
            l.remove(key);
        }
        else if (choice == 3)
        {
            l.display();
        }

        cout << endl;
    }

    return 0;
}