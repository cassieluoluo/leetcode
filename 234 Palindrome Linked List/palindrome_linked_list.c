/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (!head || !head->next) return true;
    struct ListNode *slow = head, *fast = head, *prev = NULL, *next = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow->next = prev;
        prev = slow;
        slow = next;
        next = next->next;
    }
    fast = fast ? next : slow;
    while (prev && fast) {
        if (prev->val != fast->val) return false;
        prev = prev->next;
        fast = fast->next;
    }
    return true;
}	// Author: Xinyu Chen
