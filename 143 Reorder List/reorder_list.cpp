/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* back = reverse(right);
        ListNode* next;
        while (back != nullptr) {
            next = head->next;
            head->next = back;
            back = back->next;
            head->next->next = next;
            head = next;
        }
    }
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; 
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}; // Author: XC
