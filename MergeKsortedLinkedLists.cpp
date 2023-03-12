
//  * Definition for singly-linked list.
//   struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
        
//   };
struct compare{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
            
        };
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode* headprev = new ListNode(17);
        ListNode* temp = headprev;
        while(!pq.empty()){
            ListNode* trash = pq.top();
            pq.pop();
            temp->next = trash;
            temp = temp->next;
            if(trash->next){
                pq.push(trash->next);
            }
        }
        return headprev->next;
    }
};