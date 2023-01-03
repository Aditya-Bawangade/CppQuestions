#include<stdio.h>
#define n 100
class stack{
    int* arr;
    int ptrtop;
    public:
    stack(){
        arr = new int[n];
        ptrtop = -1;
    }
    void push(int x);
    void pop();
    void displaytop();
    bool IsEmpty();
};
void stack::push(int x){
    if(ptrtop==n-1){
        printf("size of the stack exceeds");
        return;
    }
    ptrtop++;
    arr[ptrtop] = x;
}  
void:: stack::pop(){
    if(ptrtop == -1){
        return ;
    }
    printf("%d",arr[ptrtop]);
    ptrtop--;
    
    return;
}
void stack::displaytop(){
    if(ptrtop==-1){
        return;
    }
    printf("%d", arr[ptrtop]);
    return;
}  
bool stack::IsEmpty(){
    return ptrtop==-1;
}
int main(){
    stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    // printf("%d",stk.IsEmpty());
    stk.pop();
    stk.pop();
    stk.pop();
    stk.pop();
    
    stk.pop();
    

}