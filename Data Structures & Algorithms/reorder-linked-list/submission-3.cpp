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
        if (!head)
            return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* cur = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(cur) {
            ListNode* cur_next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = cur_next;
        }
        
        ListNode* list2 = prev;

        while(list2) {
            ListNode* head_next = head->next;
            ListNode* list2_next = list2->next;
            head->next = list2;
            list2->next = head_next;
            head = head_next;
            list2 = list2_next;
        }
    }
};
