#include<stdio.h>

class node{
    int data;
    class node* next;
    friend class LinkedList;
    public:
    node(int x, class node* nxt){
        data = x;
        next = nxt;
    }
    node(int x){
        data = x;
        next = NULL;
    }
    node(){
        next = NULL;
    }
};
class LinkedList{
    class node* head;
    int size;
    public:
    LinkedList();
    ~LinkedList();
    int length();
    void InsertAtHead(int x);
    void InsertAtTail(int x);
    void DeleteAtHead();
    void DeleteAtTail();
    bool search(int x);
    void display();
    void QuickSort(class node* first, class node* last);
    node* lastnode();
    node* firstnode();
    node* Partition(class node* first, class node* last);
    int operator[](int x);
};
LinkedList::LinkedList(){
    head = NULL;
    size = 0;
}
LinkedList::~LinkedList(){
    while(head!=NULL){
        class node* temp = head;
        head =temp->next;
        delete temp;
    }
}
node* LinkedList::firstnode(){
    node* temp = head;
    return head;
}
node* LinkedList::lastnode(){
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    return temp;
}
node* LinkedList::Partition(class node* first, class node* last){
    class node* pivot = first;
    class node* front = first;
    int temp = 0;
    while(front!=NULL && front!=last){
        if((front->data) < (last->data)){
            pivot = first;
            temp = front->data;
            front->data = first->data;
            first->data = temp;
            first = first->next;
        }
        front = front->next;
    }
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
void LinkedList::QuickSort(class node* first, class node* last){
    if(first == last){
        return;
    }
    class node* pivot = Partition(first,last);
    if(pivot!=NULL && pivot->next!=NULL){
        QuickSort(pivot->next, last);
    }
    if(pivot != NULL && first != pivot){
        QuickSort(first,pivot);
    }
}
int LinkedList::length(){
    return size;
}

void LinkedList::display(){
    class node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}
void LinkedList::InsertAtHead(int x){
    class node* temp = head;
    head = new node;
    head->data = x;
    head->next = temp;
    size++;
}
void LinkedList::DeleteAtHead(){
    if(head == NULL){
        return;
    }
    class node* todelete = head;
    head = head->next;
    delete todelete;
    size--;
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
void LinkedList::InsertAtTail(int x){
    if(head == NULL){
        head = new node;
        head->data = x;
        head->next = NULL;
        size++;
        return;
    }
    class node* temp = head;
    while(temp->next!=NULL){
        temp =temp->next;
    }
    class node* trash = new node;
    trash->data= x;
    trash->next= NULL;
    temp->next = trash;
    size++;

}
void LinkedList::DeleteAtTail(){
    if(head->next == NULL){
        DeleteAtHead();
        return;
    }
    class node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    class node* todelete = temp->next;
    temp->next = NULL;
    delete todelete;
    size--;
}
bool LinkedList::search(int x){
    class node* temp = head;
    while(temp!=NULL){
        if(temp->data == x){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    LinkedList l1;
    l1.InsertAtTail(1);
    l1.InsertAtTail(289);
    l1.InsertAtTail(26);
    l1.InsertAtHead(40);
   
    // l1.display();
    l1.QuickSort(l1.firstnode(), l1.lastnode());
    l1.display();
}