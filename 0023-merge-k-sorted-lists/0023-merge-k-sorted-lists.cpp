class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                res->next = list1;
                res = list1;
                list1 = list1->next;
            } else {
                res->next = list2;
                res = list2;
                list2 = list2->next;
            }
        }

        if (list1) res->next = list1;
        else res->next = list2;

        ListNode* ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];

        int mid = start + (end - start) / 2;
        ListNode* left = mergeRange(lists, start, mid);
        ListNode* right = mergeRange(lists, mid + 1, end);

        return merge(left, right);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size() - 1);
    }
};