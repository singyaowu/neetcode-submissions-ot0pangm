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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode d_start(0, head);
        ListNode *before_left = &d_start;
        ListNode *cur = head;
        ListNode *after_right = nullptr;
        for(int i = 0; i < left - 1; i++) {
            before_left = before_left->next;
        }
        cur = before_left->next;
        for(int i = 0; i < right - left; i++) {
            cur = cur->next;
        }
        after_right = cur->next;
        cur->next = nullptr;
        cur = before_left->next;
        ListNode* new_cur_next = after_right;
        while(cur != nullptr) {
            auto tmp = cur->next;
            cur->next = new_cur_next;
            new_cur_next = cur;
            cur = tmp;
        }
        before_left->next = new_cur_next;
        return d_start.next;
    }
};