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
    for(int i =1;i<n;i++){
        int current = arra[i];                   //Unable to understand the algorithm! Need help
        int j =i-1;
        while(arra[j]>current && j>=0){
            arra[j+1]=arra[j];
            j--;
        }
        arra[j+1] = current;
    }
    for(int i= 0;i<=n;i++){
        cout<<arra[i]<<endl;
    }
    return 0;
}