/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode prehead = ListNode(0);
        prehead.next = head;
        ListNode* prev = &prehead;
        ListNode* curr = &prehead;
        while (prev != nullptr) {
            curr = curr->next;
            while (curr != nullptr && curr->val == val) curr = curr->next;
            prev->next = curr;
            prev = curr;
        }
        return prehead.next;
    }
};  // Author: XC