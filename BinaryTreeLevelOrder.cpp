/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 * 
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL){
            return ans;
        }
        q.push(root);
        q.push(NULL);
        vector<int> v1;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp!=NULL){
                if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
               v1.push_back(temp->val);
            } 
            else if(q.empty()){
                ans.push_back(v1);
                v1.clear();
            }    
            else if(!q.empty()){
                q.push(NULL);
                ans.push_back(v1);
                v1.clear();
           }
       }
       return ans;

    }
};