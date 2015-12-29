/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {	// Author: Xinyu Chen
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* current = new ListNode(0);
        ListNode* prehead = current;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1 != nullptr) current->next = l1;
        else if (l2 != nullptr) current->next = l2;
        return prehead->next;
    }
};
