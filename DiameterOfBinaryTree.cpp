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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans = max(height(root->left),height(root->right));
        return 1+ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int diamleft = diameterOfBinaryTree(root->left);
        int diamright = diameterOfBinaryTree(root->right);
        int s = left+right;
        int ans = max(diamleft,diamright);
        int answer = max(ans,s);
        return answer;
    }
};