#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array ";
    cin >> n;
    int arra[n];
    for(int i =0; i<n;i++){
        cout<<"Enter an element for the array";
        cin>> arra[i];
    }
    int key;
    cout<<"Enter the key";
    cin >> key;
    int s=0;
    int e=n;
    int mid;
    while(s<=e){
         mid = (s+e)/2;
        if(arra[mid]==key){
            cout<<mid;
        }
        else if(arra[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
       
    }
    if(arra[mid]!=key){
        cout<<-1;
    }
    return 0;
}