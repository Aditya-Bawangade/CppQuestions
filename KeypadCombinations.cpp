#include<iostream>
using namespace std;
string keypadArr[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypadCombos(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int index = (int)(ch)+0;
    string ros = s.substr(1);
    string code = keypadArr[index];
    for(int i =0;i<code.length();i++){
        keypadCombos(ros,ans+code[i]);
    }
}
int main(){
    keypadCombos("12","");
}