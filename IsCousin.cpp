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
int levelOfValue(TreeNode* root, int val, int level = 0){
        if(root == NULL){
            return -1;
        }
        if(root->val == val){
            return level;
        }
        if(root->left == NULL && root->right == NULL){
            return -1;
        }
        int leftlevel = levelOfValue(root->left,val,level+1);
        int rightlevel = levelOfValue(root->right,val,level+1);
        int ans = max(leftlevel,rightlevel);
        return ans;
    }
bool SameParent(TreeNode* root, int x, int y){
        if(root == NULL){
            return false;
        }
        if(root->left!=NULL && root->right!=NULL){
            if((root->left->val == x || root->right->val == x )){
                if((root->left->val == y || root->right->val == y )){
                    return true;
                }
            }
        }
        
        return (SameParent(root->left,x,y)||SameParent(root->right,x,y));
    

    }
bool isCousins(TreeNode* root, int x, int y) {
        int a = levelOfValue(root,x,0);
        int b = levelOfValue(root,y,0);
        if(SameParent(root,x,y)){
            return false;
        }
        return (a==b);
    }
};