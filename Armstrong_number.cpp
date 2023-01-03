#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>> n;
    int originaln = n;
    int storage = 0;
    while(n>0){
        storage+= (n%10)*(n%10)*(n%10);
        n/=10;
    }
    if(originaln == storage){
        cout<<"the number is armstrong";
    }
       cout<<storage;
    return 0;
 
}
