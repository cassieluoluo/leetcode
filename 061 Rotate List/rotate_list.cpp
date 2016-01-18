/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// Author: Xinyu Chen
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
        int count = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            count++;
        }
        tail->next = head;
        for (int i = 1; i < count - k % count; i++) head = head->next;
        ListNode* newhead = head->next;
        head->next = nullptr;
        return newhead;
    }
};
