#include<stdio.h>
#include<FinalLinkedList.h>
class queue{
    LinkedList lst;
    public:
    queue();
    void enqueue(int val);
    int dequeue();
    void display();
};
queue::queue(){}
void queue::enqueue(int val){
    lst.InsertAtTail(val);
}
int queue::dequeue(){   
    int x = lst[0];
    lst.DeleteAtHead()
    return x;
}
void queue::display(){
    lst.display();
}