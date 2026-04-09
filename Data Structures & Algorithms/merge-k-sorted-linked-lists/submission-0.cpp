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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        ListNode* ret = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            ret = merge2Lists(ret, lists[i]);
        }
        return ret;
    }
    ListNode* merge2Lists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0, nullptr);
        ListNode* cur = &dummy;
        while(list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1) {
            cur->next = list1;
        } else if (list2) {
            cur->next = list2;
        }
        return dummy.next;
    }
};
