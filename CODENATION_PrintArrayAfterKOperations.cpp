#include <bits/stdc++.h> 
vector<int> printArrayAfterKOperations(vector<int> &arr, int N, int K) {
	// Naive Approach
	// for(int i = 0 ; i < K ; i++){
	// 	int maxima = arr[0] ;
	// 	for(int j = 0 ; j < N ; j++){
	// 		maxima = max(maxima, arr[j]) ;
	// 	}

	// 	for(int j = 0 ; j < N ; j++){
	// 		arr[j] = maxima - arr[j] ;
	// 	}
	// }
	// return arr ;	
	if(K == 0){
		return arr ;
	}
	else if(K % 2 == 0){
		int minima = arr[0] ;
		for(int i = 0 ; i < N ; i++){
			minima = min(arr[i], minima) ;
		}
		for(int i = 0 ; i < N ; i++){
			arr[i] = arr[i] - minima ;
		}
	}
	else{
		int maxima = arr[0] ;
		for(int i = 0 ; i < N ; i++){
			maxima = max(arr[i], maxima) ;
		}
		for(int i = 0 ; i < N ; i++){
			arr[i] = maxima - arr[i] ;
		}
	}
	return arr ;
}
