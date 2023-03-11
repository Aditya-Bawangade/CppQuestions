/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head== NULL){
            return NULL;
        }
        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode* root = head;
        ListNode* trash = head;
        ListNode* end = head;
        while(end && end->next){
            trash = root;
            root = root->next;
            end = end->next->next;
        }      
        
        trash->next = NULL;
        
        TreeNode* myroot = new TreeNode(root->val);
        myroot->left = sortedListToBST(head);
        myroot->right = sortedListToBST(root->next);
        return myroot;

    }
};