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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* fast = head, *slow = head, *slow_prev = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            slow_prev = slow;
            slow = slow->next;
        }
        slow_prev->next = nullptr;

        ListNode* prev = nullptr, *cur = slow;
        while(cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* first = head, *second = prev;
        ListNode ret;
        cur = &ret;
        while(first || second) {
            if (first) {
                cur->next = first;
                first = first->next;
                cur = cur->next;
            }
            if (second) {
                cur->next = second;
                cur = cur->next;
                second = second->next;
            }
        }
    }
};
