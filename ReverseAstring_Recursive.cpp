#include<iostream>
using namespace std;
void ReverseAString(string s){
    if(s.size()==0){
        return;
    }
    string ros = s.substr(1);           //.substr(i) removes the first i letters of the string
    ReverseAString(ros);
    cout<<s[0];
}
int main(){
    string a = "Aditya^Sai";
    ReverseAString("racecar");
}