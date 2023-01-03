#include<iostream>
using namespace std;
int CountInMaze(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    return CountInMaze(n,i+1,j)+CountInMaze(n,i,j+1);
}