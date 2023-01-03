#include<stdio.h>
#include"FinalLinkedList.h"
class stack{
    LinkedList lst;
    public:
    stack();
    void push(int val);
    int pop();
    void display();
};
stack::stack(){}
void stack::push(int val){
    lst.InsertAtHead(val);
}
void stack::display(){
    lst.display();
}
int stack::pop(){
    int x = lst[0];
    lst.DeleteAtHead();
    return x;
}
int main(){
    class  stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.pop();
    stk.display();

}