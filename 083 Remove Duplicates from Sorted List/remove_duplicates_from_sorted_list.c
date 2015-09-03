/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *left = head;
    struct ListNode *right = head;
    while (right) {
        right = right->next;
        while (right && left->val == right->val) right = right->next;
        left->next = right;
        left = left->next;
    }
    return head;
}

/* Note
	- The left pointer points to the place up to which there is no duplicate.
	- The right pointer searches the following elements until it finds the element with different value.
	- At that moment, hook the right element to the left pointer.
	- Advance both pointers by one place.
	- Once the right pointer reaches the end, we are done.
*/