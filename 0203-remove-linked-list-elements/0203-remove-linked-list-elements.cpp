class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* curr = &dummy;
        
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* duplicate = curr->next;
                curr->next = curr->next->next;
                delete duplicate;             
            } else {
                curr = curr->next;            
            }
        }
        
        return dummy.next;
    }
};