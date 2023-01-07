#include<vector>
using namespace std;
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
    vector<int> giveLeaf(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return arr;
        }
        if(root->left == NULL && root->right == NULL){
            arr.push_back(root->val);
        }
        else{
            giveLeaf(root->left, arr);
            giveLeaf(root->right, arr);
        }
        return arr;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a1;
        vector<int> a2;
        return (giveLeaf(root1,a1) == giveLeaf(root2,a2));
    }
};