#include<iostream>
using namespace std;
string RemoveDuplicates(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string answer = RemoveDuplicates(s.substr(1));
    if(ch == answer[0]){
        return answer;
    }
    return (ch + answer);
}
int main(){
    cout<<RemoveDuplicates("aaaaaabbbbbcdd");
}
