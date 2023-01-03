#include<iostream>
using namespace std;
int main(){
    int count;
    int sum = 0;
    int arra[3]= {1,2,2};
   
        for(int i =0; i<3;i++){
            count = 0;
            for(int j = i;j<3;j++){
                count+= arra[j];
                cout<<count<<endl;
                sum+=count;
             }
             
        }
    cout<<sum;
    return 0;
}