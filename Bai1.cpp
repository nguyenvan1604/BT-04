#include<iostream>
using namespace std;

typedef struct _node
{
    int data;
    struct _node *next;
} node;

node *insertFirst(node *head, int data) //chen vao dau
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    return head;
}

node *insertLast(node *head, int data) //chen vao cuoi
{
    if(head == NULL)
        return insertFirst(head,data);
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;

    node *p = head;
    while(p->next != NULL)
        p = p->next;
    p->next = newnode;
    return head;
}

node *deleteFirst(node *head) //xoa phan tu dau
{
    if(head == NULL)
        return NULL;
    node *p = head;
    head = head->next;
    delete p;
    return head;
}

node *deleteLast(node *head) //xoa phan tu cuoi
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL) //DS co 1 nut
    {
        delete head;
        return NULL;
    }
    node *p = head, *p2 = NULL;
    while(p->next != NULL)
    {
        p2 = p;
        p = p->next;
    }
    p2->next = NULL;
    delete p;
    return head;
}

void printList(node *head) //In DS
{
    if(head == NULL)
        cout<<"rong";
    node *p = head;
    while(p != NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

node *daochieu1(node *head)
{
    node *p = NULL;
    while(head != NULL)
    {
        p = insertFirst(p,head->data);
        head = head->next;
    }
    return p;
}

node *daochieu2(node *head)
{
    node *p1 = NULL, *p2 = head, *p3 = head->next;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2;
}

node *daochieu3(node *head)
{
    if(head->next->next == NULL)
    {
        head->next->next = head;
        node *p = head->next;
        head->next = NULL;
        return p;
    }
    node *p = daochieu3(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}


int main()
{
    node *head = NULL;
    for(int i=1;i<10;i++)
    {
        if(head == NULL)
            head = insertFirst(head,i);
        else
            insertLast(head,i);
    }
    cout<<"DS ban dau:\n";
    printList(head);

    cout<<"\n\nDS xoa dau:\n";
    head = deleteFirst(head);
    printList(head);

    cout<<"\n\nDS xoa cuoi:\n";
    deleteLast(head);
    printList(head);

    cout<<"\n\nDS dao nguoc lan 1:\n";
    head = daochieu1(head);
    printList(head);

    cout<<"\n\nDS dao nguoc lan 2:\n";
    head = daochieu2(head);
    printList(head);

    cout<<"\n\nDS dao nguoc lan 3:\n";
    head = daochieu3(head);
    printList(head);

    cout<<endl;
    return 0;
}







