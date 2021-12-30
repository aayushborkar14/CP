#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int node_data)
    {
        data = node_data;
        next = NULL;
    }
};
void insertNodeAtTail(Node *&head, int data)
{ //why &head and not head works because we need to modify the actual linked list
    Node *toAdd = new Node(data);

    if (head == NULL)
    {
        head = toAdd;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = toAdd;
}
Node *reverse(Node *&head)
{
    Node *prevptr = NULL;
    Node *currptr = head;
    Node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}
void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    insertNodeAtTail(head, 1);
    insertNodeAtTail(head, 2);
    insertNodeAtTail(head, 3);
    insertNodeAtTail(head, 4);

    display(head);
    cout << "hello world " << endl;
    display(head);
    return 0;
}