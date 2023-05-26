/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int util(TreeNode* root, int &ans){
    if(root == nullptr) return 0 ;
    int left = max(0, util(root->left,ans)) ;
    int right = max(0, util(root->right, ans)) ;
    
    ans = max(ans, left + right + root->val) ;
    
    return max(left, right) + root->val ;
}
int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN ;
    util(A, ans) ;
    return ans ;
}