#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int matrix1[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix1[i][j];
        }
    }
    int counter =0;
    for(int i=0;i<n;i++){
        bool a=true;
        for(int j=0;j<n;j++){
            if(matrix1[i][j] == counter){
                for(int a=0;a<n;a++){
                    matrix1[i][a]=counter;
                    
                }
                for(int b=0;b<n;b++){
                    matrix1[b][j]=counter;
                    
                }
                a=false;
                break;
            }
        }
        if(!a){
            break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix1[i][j]<<" ";
        }
        cout<<endl;
    }

}