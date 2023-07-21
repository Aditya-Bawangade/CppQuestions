#include <bits/stdc++.h> 

char findAddedCharacter(string &s, string &t) {

    int i=0;

    char ch;

    while(i<t.size()){

        if(s[i]!=t[i]){

            ch=t[i];

            break;

        }

        i++;

    }

    return ch;

}