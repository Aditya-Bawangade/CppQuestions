#include <bits/stdc++.h> 
int countDistinctBitwiseOR(vector<int>& inputVector, int size)
{
	// unordered_set<int> st, prev, curr ;

	// for(int i = 0 ; i < size ; i++){
	// 	curr.insert(inputVector[i]) ;

	// 	for(auto it : prev){
	// 		curr.insert(inputVector[i] | it) ;
	// 	}

	// 	prev = curr ;
	// 	curr.clear() ;
	// 	for(auto it : prev){
	// 		st.insert(it) ;
	// 	}
	// }
	// return st.size() ;
    vector<int> res ;
    unordered_set<int> st ;
    int left = 0 ; int right ;
    for(int a : inputVector){
        right = res.size() ;
        res.push_back(a) ;
        for(int i = left ; i < right ; i++){
            if(res.back() != (res[i] | a)){
                res.push_back(res[i] | a) ;
            }
        }
        left = right ;
    }

    for(int i = 0 ; i < res.size() ; i++){
        st.insert(res[i]) ;
    }
    return st.size() ;

// Problem 19
}