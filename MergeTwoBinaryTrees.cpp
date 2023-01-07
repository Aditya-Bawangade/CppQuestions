
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* newroot = new TreeNode();
        if(root1 != NULL && root2 != NULL){
            newroot->left = mergeTrees(root1->left,root2->left);
            newroot->right = mergeTrees(root1->right,root2->right);
        }
        // else if(root1 == NULL && root2 != NULL){
        //     newroot->left = mergeTrees(NULL,root2->left);
        //     newroot->right = mergeTrees(NULL,root2->right);
        // }
        if(root1!=NULL && root2!=NULL){ 
            newroot->val = (root1->val + root2->val);
            return newroot;
        }
        else if(root1 != NULL && root2 == NULL){
            newroot->val = root1->val;
            return root1;
        }
        else if(root1 == NULL && root2 != NULL){
            newroot->val = root2->val;
            return root2;
        }
        else{
            return NULL;
        }

    }
};