 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
//  ListNode* reverseList(ListNode* head) {
//     if(head == nullptr){
//         return head;
//     }
//     ListNode* temp = reverseList(head->next);

//     while(temp->next != nullptr && temp != nullptr){
//         temp = temp->next;
//     }
//     temp->next = head;
//     head->next = nullptr;
//     return head;
//     }
ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextptr;
    while(current != nullptr){
        nextptr = current-> next;
        current->next = prev;
        prev = current;
        current = nextptr;
    }
    return prev;
}