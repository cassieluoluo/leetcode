/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// Author: Xinyu Chen
struct TreeNode* sortedListToBST(struct ListNode* head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) {
		struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		root->val = head->val; root->left = root->right = NULL;
		return root;
	}
	struct ListNode *slow, *fast;
	slow = head;
	fast = head->next->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	root->val = slow->next->val;
	root->right = sortedListToBST(slow->next->next);
	slow->next = NULL;  // This is important, disconnect the linked list from the middle
	root->left = sortedListToBST(head);
	return root;
}
