#include<iostream>
using namespace std;
class dnode{
    public:
    int data;
    dnode* prev;
    dnode* next;
    dnode(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};
void InsertAtHead(dnode* &head, int val){
    dnode* trash = new dnode(val);
    trash->next = head;
    if(head != NULL){
    head->prev = trash;
    }
    head = trash;
    
}
void InsertAtTail(dnode* &head, int val){
    
    if(head == NULL){
        InsertAtHead(head,val);
        return;
    }
    dnode* temp = head;
    dnode* trash = new dnode(val);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = trash;
    trash->prev = temp;    
    // return;
}

void display(dnode* &head){
    dnode* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void deleteAtHead(dnode* &head){
    dnode* todelete = head;
    head = head->next;
    head->prev = NULL;
    delete todelete;
}
void deletion(dnode* &head, int pos){
    dnode* temp = head;
    if(pos ==1){
        deleteAtHead(head);
        return;
    }
    int count = 1;
    while(temp!=NULL && count!= pos){
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}
    
int main(){
    dnode* head = NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    InsertAtTail(head,6);
    InsertAtTail(head,7);
    InsertAtTail(head,8);
    
    InsertAtHead(head,9);
    deletion(head,3);
    deletion(head,1);
    display(head);
}