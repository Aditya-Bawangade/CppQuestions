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
    for(int i=0;i<n-1;i++){                         // This is a bit of a complicated loop;
        for(int j=i+1;j<n;j++){                     // The first loop indicates the position of the number which is to be swapped
            if(arra[j]<arra[i]){                    // The second loop swaps the smaller elements with respect to the first position from the array
                int temp = arra[i];                 // which remains after the first position is declared.     
                arra[i]=arra[j];                    // This way, we are able to search for the minimum element in the remaining array and swap it with
                arra[j]=temp;                       // the first position.
            }
        }
    }
    for(int i = 0;i<n;i++){
        cout<<arra[i]<<endl;
    }
    return 0;
}