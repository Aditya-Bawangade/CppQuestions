#include <bits/stdc++.h> 
/****************************************************

	Binary tree node class for reference:
	class BinaryTreeNode {
		public :
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this -> data = data;
			left = NULL;
			right = NULL;
		}
	};

****************************************************/
const int mod = 1e9 + 7 ;
void util(BinaryTreeNode<int>* root, long long currSum, long long &totalSum){
	if(root->left == nullptr && root->right == nullptr){
		currSum = ((long long)currSum*10LL + (long long)root->data)%mod ;
		totalSum = (totalSum + currSum)%mod ;
		return ;
	}
	currSum = (currSum*10 + root->data)%mod ;

	if(root->left != nullptr){
		util(root->left, currSum, totalSum) ;
	}
	if(root->right != nullptr){
		util(root->right, currSum, totalSum) ;
	}
}
int rootToLeafSum( BinaryTreeNode<int>* root) {
	long long currSum = 0 ;
	long long totalSum = 0 ;
	util(root, 0LL, totalSum) ;

	return (int)totalSum ;
}
// #include <bits/stdc++.h> 
// /****************************************************

// 	Binary tree node class for reference:
// 	class BinaryTreeNode {
// 		public :
// 		T data;
// 		BinaryTreeNode<T> *left;
// 		BinaryTreeNode<T> *right;

// 		BinaryTreeNode(T data) {
// 			this -> data = data;
// 			left = NULL;
// 			right = NULL;
// 		}
// 	};

// ****************************************************/
// const int mod = 1e9 + 7;

// void sumNumbers(BinaryTreeNode<int> *root, long long curSum, long long &totalSum){
//     if (root->left == NULL and root->right == NULL)
//     {
//         curSum = ((long long)curSum * 10LL + (long long)root->data) % mod;
//         totalSum = (totalSum + curSum) % mod;
//         return;
//     }

//     curSum = (curSum * 10 + root->data) % mod;
//     // If left node exists, move to the left substree.
//     if (root->left)
//     {   
//         sumNumbers(root->left, curSum, totalSum);
//     }
//     // If right node exists, move to the right substree.
//     if (root->right)
//     {
//         sumNumbers(root->right, curSum, totalSum);
//     }
// }
// int rootToLeafSum( BinaryTreeNode<int>* root) {
//     long long ans = 0;
//     // Call the function "SUMNUMBERS".
//     sumNumbers(root, 0LL, ans);
//     return (int)ans;
// }
