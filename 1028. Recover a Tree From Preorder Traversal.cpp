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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> ans ;
        for(int i = 0, level, val ; i < traversal.length();){
          for(level = 0 ; i < traversal.length() && traversal[i] == '-' ; i++){
            level++ ;
          }
          for(val = 0 ; i < traversal.length() && traversal[i] != '-'; i++){
            val = val*10 + traversal[i] - '0' ;
          }
          TreeNode* trash = new TreeNode(val) ;

          while(ans.size() > level){
            ans.pop_back() ;
          }
          if(!ans.empty()){
            if(!ans.back()->left){
              ans.back()->left = trash ;
            }
            else{
              ans.back()->right = trash ;
            }
            
          }
          ans.push_back(trash) ;
        }
        return ans[0] ;
    }

};