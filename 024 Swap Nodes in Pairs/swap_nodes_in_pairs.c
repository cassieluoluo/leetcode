/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head->next;
    temp->next = swapPairs(temp->next);
    head->next = temp->next;
    temp->next = head;
    return temp;
} // Author: Xinyu Chen
