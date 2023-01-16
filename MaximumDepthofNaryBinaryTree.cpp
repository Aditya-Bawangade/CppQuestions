/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // int maxDepth(Node* root) {
    //     if(root == NULL){
    //         return 0;
    //     }
    //     vector<int> values; 
    //     for(int i = 0 ; i< root->children.size(); i++){
    //         values.push_back(maxDepth(root->children[i]));
    //     }
    //     if(values.empty()){
    //         return 1;
    //     }
    //     int max = *max_element(values.begin(),values.end());
    //     return max+1;
    // }
     int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        int depth = 0;
        for(auto child:root->children){
            depth = max(depth, maxDepth(child));
        }
        return 1+depth;
    }
};