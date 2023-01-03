#include<iostream>
using namespace std;
string MoveX(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string answer = MoveX(s.substr(1));
    if(ch=='x'){
        return (answer+ch);
    }
    return (ch+answer);
}
int main(){
    cout<<MoveX("xadxixtxyxax");
}