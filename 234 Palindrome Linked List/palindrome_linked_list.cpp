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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        ListNode *next = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow->next = prev;
            prev = slow;
            slow = next;
            next = next->next;
        }
        if (fast == nullptr) fast = slow;
        else fast = next;
        while (fast != nullptr) {
            if (fast->val != prev->val) return false;
            fast = fast->next;
            prev = prev->next;
        }
        return true;
    }
};
