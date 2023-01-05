#include<iostream>
#include<string>
using namespace std;
int i = 0;
int j = 0;
int MemoizationArray[20][20];


//Worst method, worst time complexity
// int LongestCommonSubsequence(string text1, string text2){
//     if(text1[i]=='\0' || text2[j]=='\0'){
//         return 0;
//     }

//     else if(text1[i]==text2[j]){
//         string t1 = text1.substr(i+1);
//         string t2 = text2.substr(j+1);
//         return (1 + LongestCommonSubsequence(t1,t2));
//     }
//     else{
//         string t1 = text1.substr(i+1);
//         string t2 = text2.substr(j+1);
//         return max(LongestCommonSubsequence(text1,t2), LongestCommonSubsequence(t1,text2));
//     }
// }
int LongestCommonSubsequenceMemoization(string text1, string text2,int m = 0, int n = 0){
    // int i = 0;
    // int j = 0;
    
    if(m == 0 && n == 0){
        m = text1.length();
        n = text2.size();
    }
    if(text1[0]=='\0' || text2[0]=='\0'){
        return 0;
    }
    // if(MemoizationArray[i][j] != -1){
    //     return MemoizationArray[i][j];
    // }
    if(text1[0]==text2[0]){
        string t1 = text1.substr(1);
        string t2 = text2.substr(1);
        if(MemoizationArray[m-text1.length()][n-text2.length()] != -1){
            return (MemoizationArray[m-text1.length()][n-text2.length()]);
        }
        MemoizationArray[m-text1.length()][n-text2.length()] = 1 + LongestCommonSubsequenceMemoization(t1, t2, m, n);
        return MemoizationArray[m-text1.length()][n-text2.length()];
    }
    else{
        string t1 = text1.substr(1);
        string t2 = text2.substr(1);
        if(MemoizationArray[m-text1.length()][n-text2.length()] != -1){
            return MemoizationArray[m-text1.length()][n-text2.length()];
        }
        MemoizationArray[m-text1.length()][n-text2.length()]  = max(LongestCommonSubsequenceMemoization(text1,t2,m,n),LongestCommonSubsequenceMemoization(t1,text2,m,n));
        return  MemoizationArray[m-text1.length()][n-text2.length()];
    }
}
int main(){
    string s1 = "pmjghexybyrgzczy";
    string s2 = "hafcdqbgncrcbihkd";
   for(int a=0;a<s1.size();a++){
    for(int b = 0; b<s2.size();b++){
        MemoizationArray[a][b] = -1;
        
    }
   
   }
   cout<<LongestCommonSubsequenceMemoization(s1,s2)<<endl;
  

    }