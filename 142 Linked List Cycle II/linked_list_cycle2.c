/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next) return NULL;
    struct ListNode *slow = head->next, *fast = head->next->next;
    while (slow != fast) {
        if (!fast || !fast->next) return NULL;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}	// Author: Xinyu Chen
