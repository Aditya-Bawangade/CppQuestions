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
    vector<vector<int>> vec ;
    void util(TreeNode* root, int i, int j){
        if(root == nullptr) return ;
        vector<int> trash = {i, j, root->val} ;
        vec.push_back(trash) ;
        util(root->left, i+1, j-1) ;
        util(root->right, i+1, j+1) ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        util(root, 0, 0) ;
        sort(vec.begin(), vec.end(), [](const vector<int> &a, const vector<int> &b){return (a[1]==b[1]) ? ((a[0] == b[0]) ? (a[2] < b[2]) : (a[0] < b[0])) : a[1] < b[1] ;}) ;
        vector<vector<int>> ans ;
        int i = 0 ; 
        while(i < vec.size()){
            vector<int> trash ;
            int col = vec[i][1] ;
            trash.push_back(vec[i][2]) ;
            
            int j = i + 1 ; 
            // if(j >= vec.size()) break ;
            while(j < vec.size()){
                if(vec[j][1] == col){
                    trash.push_back(vec[j][2]) ;
                    j++ ;
                }
                else{
                    break ;
                }
            }
            i = j ;
            ans.push_back(trash) ;
        }
        return ans ;
    }
};