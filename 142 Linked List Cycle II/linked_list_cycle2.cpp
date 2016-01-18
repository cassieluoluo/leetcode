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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        if (head == nullptr || head->next == nullptr) return NULL;
        fast = head;
        slow = head;
        do {
            if (fast == nullptr || fast->next == nullptr) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);
        
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};