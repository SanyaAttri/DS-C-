#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d):data(d), next(NULL), prev(NULL)
    {
    }
};
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;

        head= newNode;
    }
}
void insertAtTail(Node*&head, Node*&tail, int data)
{
        Node *newNode = new Node(data);

    if(tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

}
void print(Node *head)
{
    cout<<"\n List Content\n";
    if(head ==NULL)
        cout<<"\n Empty List \n";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main()
{
    Node *head, *tail;
    head = tail = NULL;

insertAtHead(head,tail, 10);
print(head);

insertAtHead(head,tail, 20);
print(head);

insertAtTail(head,tail, 150);
print(head);
insertAtTail(head,tail, 410);
print(head);
return 0;}
