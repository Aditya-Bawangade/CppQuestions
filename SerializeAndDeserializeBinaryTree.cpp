/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    TreeNode* util(queue<string> &Q){
        string s = Q.front() ;
        Q.pop() ;
        if(s == "null"){return NULL ;} 
        TreeNode* trash = new TreeNode(stoi(s)) ;
        trash->left = util(Q) ;
        trash->right = util(Q) ;
        return trash ;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "null," ;
        }
        string val = to_string(root->val) + ",";
        string left = serialize(root->left) ;
        string right = serialize(root->right) ;
        return  val + left + right ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> Q ; 
        string s = "" ;
        for(char c: data){
            if(c==','){
                Q.push(s) ;
                s = "";
            }
            else{
                s += c ;
            }

        }
        return util(Q) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));