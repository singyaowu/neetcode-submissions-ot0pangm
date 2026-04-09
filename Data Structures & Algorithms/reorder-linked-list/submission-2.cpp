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
        ListNode *fast = head->next, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* cur = slow->next, *prev = nullptr;
        slow->next = nullptr;
        while (cur) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode* first = head, *sec = prev;
        while (sec) {
            auto tmp = first->next;
            auto tmp2 = sec->next;
            first->next = sec;
            sec->next = tmp;
            first = tmp;
            sec = tmp2;
        }
    }
};
