#include<string>
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
    int flag = 0;
    int spacecount = 0;
    int wl = searchWord.length();
     for(int i = 0 ; i< sentence.length(); i++){
         if(sentence[i] == ' '){
             spacecount++;
         }
        if(i == 0|| sentence[i-1] == ' ' ){
            if(sentence.compare(i, wl, searchWord)==0){
                flag = flag + spacecount + 1;
                break;
            }
         }
     }
     if(flag==0){
         return -1;
     } 
     return flag;  
    }
};