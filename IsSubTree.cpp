#include<iostream>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool IsSame(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }
        if(root1 == NULL || root2 == NULL){
            return false;

        }
        if(IsSame(root1->left,root2->left) && IsSame(root1->right,root2->right)){
            if(root1->val == root2->val){
                return true;
            }
        }
        return false;

    }
    // bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    //     if(root == NULL && subRoot == NULL){
    //         return true;
    //     }
    //     if(root == NULL || subRoot == NULL){
    //         return false;
    //     }
    //     if(IsSame(root,subRoot)){
    //         return true;
    //     }
    //     return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    //     // if((isSubtree(root->left,subRoot) == 1) || (isSubtree(root->right,subRoot) == 1)){
    //     //      return true;
    //     //  }
    //     // else if((isSubtree(root->left,subRoot) == 0) && (isSubtree(root->right,subRoot) == 0)){
            
    //     //         return IsSame(root,subRoot);
            
    //     // }
    // }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL){
            return true;
        }
        if(root == NULL || subRoot == NULL){
            return false;
        }
        bool a = isSubtree(root->left,subRoot);
        bool b = isSubtree(root->right,subRoot);
        if((a == 1) || (b == 1)){
             return true;
         }
        else if((a== 0) && (b == 0)){
            
                return IsSame(root,subRoot);
            
        }
        return false;
    }
};