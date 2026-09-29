class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
        
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                res->next = list1;
                res = list1;
                list1 = list1->next; 
            }
            else{
                res->next = list2;
                res = list2;
                list2 = list2->next;                
            }
        } 
        if(list1) res->next = list1;
        else res->next = list2;

        ListNode* head = dummyNode->next;
        delete dummyNode; 
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};