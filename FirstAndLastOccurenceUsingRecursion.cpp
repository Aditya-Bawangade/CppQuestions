#include<iostream>
using namespace std;
int firstOccurence(int arra[], int size, int ptr, int key){
    if(ptr == size){
        return -1;
    }
    if(arra[ptr] == key){
        return ptr;
    }
    return firstOccurence(arra, size, ptr+1, key);
}
int LastOccurence(int arra[], int size, int ptr, int key){
    if(ptr == size){
        return -1;
    }
   
    int RemainingArray = LastOccurence(arra, size, ptr+1,key);
    if(RemainingArray != -1){
        return RemainingArray;
    }
    if(arra[ptr] == key){
        return ptr;
    }
    return -1;
}
int main(){
    int arra[10] = {1,22,3,4,5,5,6,5,6,6};
    cout<< LastOccurence(arra,  10, 0, 5);
}
