/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || k == 0) return head;
    int len = 1;
    struct ListNode *curr = head, *newhead;
    while (curr->next) {
        len++;
        curr = curr->next;
    }
    curr->next = head;
    for (int i = 1; i < len - k % len; i++) head = head->next;
    newhead = head->next;
    head->next = NULL;
    return newhead;
}	// Author: Xinyu Chen
