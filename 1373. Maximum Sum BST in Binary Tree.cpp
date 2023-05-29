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

    class pope{
        public: 
            int maxima ;
            int mini ;
            bool isbst ;
            int sum ;
    };
    pope solve(TreeNode* root, int &ans){
        if(root == nullptr) {
            return {INT_MIN, INT_MAX, true, 0} ;
        }
        pope left = solve(root->left, ans) ;
        pope right = solve(root->right, ans) ;

        pope curr ;
        curr.sum = left.sum + right.sum + root->val ;
        curr.maxima = max(root->val, right.maxima) ;
        curr.mini = min(root->val, left.mini) ;

        if(left.isbst && right.isbst && (root->val > left.maxima && root->val <  right.mini)){
            curr.isbst = true ;
        }
        else{
            curr.isbst = false ;
        }
        if(curr.isbst){
            ans = max(ans, curr.sum) ;
        }
        return curr ;
    }
    int maxSumBST(TreeNode* root) {
        int maxs = 0 ;
        pope trash = solve(root, maxs) ;
        return maxs ; 
    }
};