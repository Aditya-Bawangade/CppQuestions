//Bubble_sort
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
    for(int i=1;i<=n-1;i++){
        for(int j = 0; j<n-i;j++){
            if(arra[j+1]>arra[j]){
                int temp = arra[j+1];     
                arra[j+1] = arra[j];
                arra[j] = temp;
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arra[i]<<endl;
    }
    return 0;
}