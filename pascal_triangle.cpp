#include<iostream>
using namespace std;
int factorial(int n){
    int num =n;
    if(n == 0){
        num = 1;
    }
    for(int i=n-1;i>=1;i--){
        num*=i;
    }
 
    return num;
}
int nCr(int n, int r){
    int ncr;
    ncr=factorial(n)/((factorial(r))*(factorial(n-r)));
    return ncr;
}
int main(){
    int n =10;
    for(int i =0;i<=n;i++){
        for(int j =0; j <= i; j++){
            cout<<nCr(i,j)<<" "; //Very important line! tells us how to add space in patterns
        }
        cout<<endl;
    }
    return 0;
}