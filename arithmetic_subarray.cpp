#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int answer = 2;                                     //Atleast two will be the length of the longest arithmetic subarray
    int comm_diff = array[1]- array[0];
    int length = 2;
    int i =2;
    while(i<n){
        if(array[i]-array[i-1] == comm_diff){           // if the next two elements have the same common difference then we increase the length
            length++;
        }
        else{
            comm_diff = array[i] - array[i - 1]; // if the next two elements have another common diff then we change the common diff and change the length and yet, the answer variable will store the previous length until our new length is more than the earlier obtained length
            length = 2;
        }
        if(length>answer){
            answer= length;
        }
        i++;
    }
    cout<<answer;
    return 0;
}