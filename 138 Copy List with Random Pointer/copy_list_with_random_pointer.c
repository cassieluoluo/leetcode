/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	struct RandomListNode *curr, *node, *dummy, *pointer;
	curr = head;
	while (curr) {
		node = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
		node->label = curr->label;
		node->next = curr->next;
		node->random = NULL;
		curr->next = node;
		curr = node->next;
	}
	curr = head;
	dummy = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
	dummy->next = head;
	pointer = dummy;
	while (curr) {
		if (curr->random) {
			curr->next->random = curr->random->next;
		}
		pointer = pointer->next->next;
		curr = curr->next->next;
	}
	curr = head;
	pointer = dummy;
	while (curr) {
		pointer->next = pointer->next->next;
		pointer = pointer->next;
		curr->next = curr->next->next;
		curr = curr->next;
	}
	return dummy->next;
}
// Author: XC