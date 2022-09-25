#include <string>

using namespace std;

class Pair
{
public:
    string name;
    int age;
};

class Node
{
public:
    Pair data;
    Node *next, *prev;

    Node(Pair data)
    {
        this->data.name = data.name;
        this->data.age = data.age;
        this->next = NULL;
        this->prev = NULL;
    }
};

#include <iostream>
#include <climits>

using namespace std;

Node *takeinput(int n)
{
    cout << endl;
    cout << "Enter the Name and age of the Member :" << endl;
    Pair data;
    Node *head = NULL, *tail = NULL;
    while (n--)
    {
        cin >> data.name >> data.age;
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void print(Node *head)
{
    cout << endl;
    cout << "The details of the members in the Linked List are arranged on the basis of their age " << endl;
    cout << endl;
    Node *temp = head;
    cout << "Printing the details from forward to end in a Linked List :" << endl;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            cout << temp->data.name << " : " << temp->data.age << " -> ";
        }
        else
        {
            cout << temp->data.name << " : " << temp->data.age;
        }
        temp = temp->next;
    }
    cout << endl;
    cout << "Printing the details from end to forward in a Linked List :" << endl;
    Node *temp1 = head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    while (temp1 != NULL)
    {
        if (temp1->prev != NULL)
        {
            cout << temp1->data.name << " : " << temp1->data.age << " -> ";
        }
        else
        {
            cout << temp1->data.name << " : " << temp1->data.age;
        }
        temp1 = temp1->prev;
    }
}

Node *relation(Node *head, int n)
{
    int tempAge = INT_MAX;
    Node *temp1 = head;
    for (int i = 0; i < n; i++)
    {
        Node *temp = temp1;
        tempAge = temp->data.age;
        while (temp != NULL)
        {
            if (temp->data.age > tempAge)
            {
                swap(temp1->data, temp->data);
                tempAge = temp->data.age;
            }
            temp = temp->next;
        }
        temp1 = temp1->next;
    }
    return head;
}

int main()
{
    int n;
    cout << "Enter the number of members in family : ";
    cin >> n;

    Node *head = takeinput(n);
    head = relation(head, n);
    print(head);

    return 0;
}