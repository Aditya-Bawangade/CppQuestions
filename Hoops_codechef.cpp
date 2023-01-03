#include<iostream>
using namespace std;
int main(){
    int T;
    cin>> T;
    for(int i=1;i<=T;i++){
        int N;
        cin>>N;
        int a=0;
        if(N==1){
            a = 1;
            cout<<a<<endl;
        }
        else{
            a =(N+1)/2;
            cout<<a<<endl;
        }
    }
    return 0;
}