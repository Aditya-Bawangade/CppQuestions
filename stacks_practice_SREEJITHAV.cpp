#include <stdio.h>
class node
{
private:
    int data;
    node *next;

public:
    node(int val, node *nxt);
    ~node();
    friend class LinkedList;
};
node::node(int val = 0, node *nxt = NULL)
{
    data = val;
    next = nxt;
}
node::~node()
{
}
class LinkedList
{
private:
    int size;
    node *head;

public:
    LinkedList();
    ~LinkedList();
    void InsertAtHead(int value);
    void InsertAtTail(int value);
    void display();
    void deletion(int val);
    void deleteAtHead();
    void deleteAtTail();
    void Reverse();
    int operator[](int x);
};
LinkedList::LinkedList()
{
    size = 0;
    head = NULL;
}
LinkedList::~LinkedList()
{
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
void LinkedList::InsertAtHead(int value)
{
    head = new node(value, head);
    size++;
}
void LinkedList::InsertAtTail(int value)
{
    if (head == NULL)
    {
        head = new node(value, head);
        size++;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node(value);
    size++;
    return;
}
void LinkedList::display()
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("->");
        temp = temp->next;
    }
    printf("NULL");
    return;
}
void LinkedList::deletion(int value)
{
    node *temp = head;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        node *todelete = head;
        head = head->next;
        delete todelete;
        size--;
    }
    while (temp->next->data != value)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    size--;
    return;
}
void LinkedList::deleteAtHead()
{
    node *todelete = head;
    if (head)
        head = head->next;
    size--;
    delete todelete;
    return;
}
void LinkedList::deleteAtTail()
{
    node *temp = head;
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *todelete = temp->next;
    temp->next = NULL;
    delete todelete;
    return;
}
void LinkedList::Reverse()
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nextptr;
    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
    return;
}
int LinkedList::operator[](int x){
    if(head==NULL || size<x){
        printf("Error");
        return 0;
    }
    node* temp = head;
    int counter = 0;
    while(temp!=NULL && counter<x-1){
        temp = temp->next;
        counter++;
    }
    return temp->data;
}
class stack{
    private:
        LinkedList lst;
    public:
    stack();
    void push(int x);
    int pop();
    void display();
};
stack::stack(){

}
void stack::push(int x){
    lst.InsertAtHead(x);
}
int stack::pop(){
    
    int x = lst[0];
    lst.deleteAtHead();
    return x;

}
void stack::display(){
    lst.display();
    return;
}
class Queue{
    private:
    LinkedList lst;
    public:
    void push(int x);
    int pop();
    void display();
};
void Queue::display(){
    lst.display();
}
void Queue::push(int x){
    lst.InsertAtTail(x);
    return;
}
int Queue::pop(){
    int x = lst[0];
    lst.deleteAtHead();
    return x;
}
int main()
{
    // LinkedList l1;
    // l1.InsertAtTail(1);
    // l1.InsertAtTail(2);
    // l1.InsertAtTail(3);
    // l1.InsertAtTail(4);
    // l1.InsertAtTail(5);
    // l1.InsertAtTail(6);
    // l1.InsertAtTail(7);
    // l1.InsertAtTail(8);
    // l1.Reverse();
    // l1.display();
    // stack stk;
    // stk.push(1);
    // stk.push(2);
    // stk.push(3);
    // stk.push(4);
    // stk.push(5);
    // // stk.display();
    // stk.pop();
    // stk.display();
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.pop();
    q1.display();
}