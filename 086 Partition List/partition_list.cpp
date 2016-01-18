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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode* lp = &left;
        ListNode* rp = &right;
        while (head != nullptr) {
            if (head->val < x) {
                lp->next = head;
                lp = lp->next;
            } else {
                rp->next = head;
                rp = rp->next;
            }
            head = head->next;
        }
        lp->next = right.next;
        rp->next = nullptr;
        return left.next;
    }
};