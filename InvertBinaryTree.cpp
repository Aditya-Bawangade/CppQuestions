#include<iostream>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  TreeNode* InvertedTree(TreeNode* root){
    if(root == NULL){
        return root;
    }
    InvertedTree(root->left);
    InvertedTree(root->right);
    TreeNode* trash = new TreeNode;
    trash = root->left;
    root->left = root->right;
    root->right = trash;
    return root;
  }
  //Accepted