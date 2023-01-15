
//  Definition for a binary tree node.
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
    void DFS(TreeNode* root, string path, vector<string> &answer){
        if(root == NULL){
            return;
        }
        path += to_string(root->val);
        if(root->right == NULL && root->left == NULL){
            answer.push_back(path);
        }
        else{
            path += "->";
            DFS(root->left,path,answer);
            DFS(root->right,path,answer);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> answer;
        if(root == NULL){
            return answer;
        }
        string path="";
        DFS(root,path,answer);
        return answer;
    }
};