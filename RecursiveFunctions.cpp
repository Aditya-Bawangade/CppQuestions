#include<iostream>
using namespace std;
bool checkSortedArray(int arra[], int sizeOfArray){
    if(sizeOfArray==1){
        return true;
    }
   bool remainingArray = checkSortedArray(arra+1, sizeOfArray - 1);
   return (arra[0]<arra[1] && remainingArray);
}
int main(){
    int ad[]={65,4,6,7,9};
    cout<<checkSortedArray(ad,5);
    return 0;
}