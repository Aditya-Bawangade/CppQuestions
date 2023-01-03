#include<iostream>
using namespace std;
void Subseq(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch = s[0];
    string remainingString = s.substr(1);
    Subseq(remainingString,ans);
    Subseq(remainingString,ans+ch);
}
int main(){
    Subseq("ABC","");
    cout<<endl;

}