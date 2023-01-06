#include<iostream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp->next;
        }
        delete temp;
        int mid;
        if(size%2 == 0){
            mid = (size/2) + 1;
        }
        else{
            mid = (size+1)/2;
        }
        ListNode* temp2 = head;
        int counter = 0;
        while(temp2 != nullptr){
            if(counter == mid-1){
                return temp2;
            }
            counter++;
            temp2 = temp2->next;
        }
        return temp;
        
    }
};