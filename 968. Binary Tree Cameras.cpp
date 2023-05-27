/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0 ;
    // returns 0  if root == leaf;
    // returns 1 if root == parent of a leaf
    // returns 2 if it is covered already
    int util(TreeNode* root){
        if(root == nullptr) return 2 ;
        int left = util(root->left), right = util(root->right) ;

        if(left == 0 || right == 0){
            res++ ;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0 ;
    }
    int minCameraCover(TreeNode* root) {
        return (util(root) < 1 ? 1 : 0) + res ; 
    }
};