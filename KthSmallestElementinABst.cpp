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
    void traversetree(TreeNode* root, vector<int> &arr){
        if(root == NULL){
            return;
        }
        traversetree(root->left, arr);
        traversetree(root->right, arr);
        arr.push_back(root->val);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        traversetree(root,arr);
        sort(arr.begin(),arr.end());
        // for(int i =0; i<size;i++){
        //     cout<<arr[i]<<" ";
        // }
        return arr[k-1];
    }
};