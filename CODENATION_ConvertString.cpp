
#include <bits/stdc++.h> 
string convertString(string str) 
{
	if(str[0] != ' ' && !isupper(str[0])){
		char temp = toupper(str[0]) ;
		str[0] = temp ;
	}
	for(int i = 1 ; i < str.size() ; i++){
		if(str[i - 1] == ' '){
			if(!isupper(str[i])){
				char temp = toupper(str[i]) ;
				str[i] = temp ;
			}
		}
	}
	return str ;
}