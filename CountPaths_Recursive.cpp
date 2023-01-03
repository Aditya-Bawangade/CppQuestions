#include<iostream>
using namespace std;
int count(int s,int e){
    if(s==0){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int counter=0;
    for(int i=0;i<6;i++){
        count(s+i,e);
    }
}
int main(){
    
}