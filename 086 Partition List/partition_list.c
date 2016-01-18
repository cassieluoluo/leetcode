/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if (!head) return NULL;
    struct ListNode lo, hi;
    lo.next = NULL;
    hi.next = NULL;
    struct ListNode *plo = &lo, *phi = &hi;
    while (head) {
        if (head->val < x) {
            plo->next = head;
            plo = plo->next;
        }
        else {
            phi->next = head;
            phi = phi->next;
        }
        head = head->next;
    }
    plo->next = hi.next;
    phi->next = NULL;
    return lo.next;
}	// Author: Xinyu Chen
