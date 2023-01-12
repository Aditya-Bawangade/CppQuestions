
// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        delete temp;
        int flag = 0;
        int ctr = 0;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        if(size%2 == 0){
            while(ptr2 != NULL && ctr<size/2){
                ctr++;
                ptr2 = ptr2->next;
            }
        }
        else{
            while(ptr2 != NULL && ctr<size/2){
                ctr++;
                ptr2 = ptr2->next;
            }
            ptr2 = ptr2->next;
        }
        if(size == 1){
            return true;
        }
        int arr1[size/2];
        int arr2[size/2];
        int count = 0;
        while(ptr1 != NULL && ptr2 != NULL){
            arr1[count] = ptr1->val;
            arr2[count] = ptr2->val;
            count++; 
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        for(int i = 0; i< size/2; i++){
          if(arr1[i] != arr2[size/2-i-1]){
              return false;
          }
        }
    // if(flag == size/2){
    //     return true;
    // }
    return true;
        
    }
};