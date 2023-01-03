#include<iostream>
using namespace std;
int power(int num, int p){
    int a = num;
    for(int i =1;i<p;i++){
        a = a*num;
    }
    if(num ==0 && p ==0){
        a = 0;
    }
    if(p == 0 && num !=0){
        a =1;
    }
    return a;
}
int binaryToDecimal(int n){
    int ans =0;
    int x =1;
    while(n>0){
        int y =n%10;
        ans+=x*y;x*=2;
        n/=10;
    }

    return ans;
}
int main(){
   int n = 111;
    int count = 0;
    int ans = 0;
    int lastdigit;
    cout<<10%2; 
    while(n>0){
        lastdigit = n%10;
        cout<<lastdigit;
        int j = power(2,count);
        cout<<j<<endl;
        cout<<j*lastdigit;
        ans= ans + (j*lastdigit);
        cout<<ans<<endl;
        n = n/10;
        count+=1;
    }
    cout<<ans;

    return 0;
}