#include<iostream>
using namespace std;
class Node
{
public:

    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;/////////////////////////////////////////////////////
        next = NULL;
    }
};

void addAtFront(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

class demo
{
    double data[20];
    char ch,ch2,ch3,ch4,ch5;
};
/*

void addAtFront(Node *&head, int data)
{
    Node *newNode = new Node(data);

/// Method 1
    if(head == NULL)
        head = newNode;
    else
    {
         newNode->next = head;
        head = newNode;
    }

////
/// Method 2
    if(head != NULL)
         newNode->next = head;

    head = newNode;
////
/// Method 3
    newNode->next = head;
    head = newNode;

}
*/

Node* addAtTail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if(head==NULL)
        head = newNode;
    else
    {
        Node *temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    return head;///////////////////////////////////////////////////////
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

bool find(Node *head,int key)
{
    if(head == NULL)
        return false;

    if(head->data == key)
        return true;
    return find(head->next, key);//////////////////////////////////////////(head,key)
}

int getLength(Node *head)
{
    int len= 0;
    while(head!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
void insertAtN(Node *&head, int pos, int data)
{
    int length = getLength(head);
        Node *newNode = new Node(data);
    if(head == NULL)
        head = newNode;
    else if(pos<0)
        addAtFront(head, data);
    else if(pos>length)
        head = addAtTail(head, data);
    else
    {
        Node *temp = head;
        int jump=0;
        while(jump<pos)
        {
            temp = temp->next;
            jump ++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

Node* getMid(Node*head)     ///////////////////////////////////////////////
{                          ////////////////////////////////////////////////
    if(head==NULL)
        return NULL;
    Node*slow =head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node *&head)//////////////////////////////////////////////////////////
{
    Node *prev = NULL, *current = head, *next = NULL;
        while(current != NULL)
        {
            next  = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev; ///////////////////////////////////////////////////////////////////
}
Node* merge(Node *a, Node*b)
{
    if(a==NULL)
        return b;
    if (b==NULL)
        return a;
    Node *newHead;
    if(a->data < b->data)
    {
        newHead = a;
        a->next = merge(a->next,b);
    }
    else
    {
        newHead = b;
        b->next = merge(a, b->next);
    }
    return newHead;
}

void deleteAll(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}
Node* removefromHead(Node *head)
{
    Node *temp = head;
    head = head->next;

    delete temp;
    return head;
}
Node* deleteFromPos(Node *head, int pos)
{
    if(head==NULL)
        return NULL;
    else
    {
        Node *temp = head;
        int jump =0;
        while(jump<pos-1)
        {
            jump++;
            temp=temp->next;
        }

        if(pos ==0)
        {
            head = head->next;
            return head;
        }
        Node *temp2 = temp->next;
        temp->next= temp->next->next;
        delete temp2;

        return head;

     }
}

Node * mergeSort(Node *head)
{
    if(head == NULL || head->next==NULL)
        return head;
    Node *mid = getMid(head);
    Node *a = head;
    Node *b = mid->next;
    mid->next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a,b);
}

bool isCyclePresent(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL && slow != fast)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == slow)
        return true;
    return false;
}

int main()
{
    cout<<"\nsize = "<<sizeof(demo);
    Node *head = NULL;
    addAtFront(head, 30);
    print(head);

    addAtFront(head, 20);
    print(head);

    addAtFront(head, 10);
    print(head);

    head  = addAtTail(head, 50);
    print(head);

    insertAtN(head, 2, 40);
    print(head);


    Node *head2 = NULL;
    addAtFront(head2, 70);
    print(head2);

    addAtFront(head2, 30);
    print(head2);

    addAtFront(head2, 5);
    print(head2);

cout<<"\nMerged\n";
    Node *merged = merge(head, head2);
    print(merged);
        addAtFront(merged, 555);
        addAtFront(merged, 999);

    //head = reverse(head);
    print(merged);
    merged = mergeSort(merged);
    print(merged);

    merged = deleteFromPos(merged, 2);
    print(merged);

 cout<<"\n Find 20 "<<find(head, 20);
    cout<<"\n Find 90 "<<find(head, 90);
    cout<<"\n Mid "<<getMid(head)->data;

    Node*temp = merged;
    while(temp->next!=NULL)
        temp = temp->next;

    //temp->next = merged->next->next;

    cout<<"\n Cycle Present = "<<isCyclePresent(merged);




/*
    Node n1(10), n2(20), n3(30);

    n1.next = &n2;
    n2.next = &n3;

cout<<"\n";
    for(Node *start = &n1;start!=NULL;start = start->next)
        cout<<start->data<<" ";
        */
}
