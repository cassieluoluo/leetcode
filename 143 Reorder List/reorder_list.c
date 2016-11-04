/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {
    struct ListNode *fast = head, *slow = head;
    if (!fast || !fast->next || !fast->next->next) return;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *curr = slow->next;
    slow->next = NULL;
    struct ListNode *prev = NULL;
    struct ListNode *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
	struct ListNode *back = prev;
	struct ListNode *next1, *next2;
    while (back) {
        next1 = head->next;
		next2 = back->next;
		head->next = back;
		back->next = next1;
		head = next1;
		back = next2;
    }
} /* Author: XC */
