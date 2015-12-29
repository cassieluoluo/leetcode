/** Author: Xinyu Chen
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pt1 = new ListNode(0);
        pt1->next = head;
        ListNode* pt2 = pt1;
        for (int i = 0; i < n; i++) {
            pt2 = pt2->next;
        }
        while (pt2->next != NULL) {
            pt1 = pt1->next;
            pt2 = pt2->next;
        }
        if (pt1->next == head) return head->next;
        pt1->next = pt1->next->next;
        return head;
    }
};