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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode *left = head, *right = head->next;
        while (right) {
            if (left->val == right->val) {
                left->next = right->next;
                right = right->next;
            } else {
                left = left->next;
                right = right->next;
            }
        }
        return head;
    }
};

/* Note
	- This is an easy-to-understand solution although there are faster code.
	- We maintain two pointers: left and right. Left pointer points to the element up to which there is no duplicate.
	  Right pointer points to the element to be checked.
	- Now we have two situations: if the left and right pointer has the same value, that indicates the second one is a duplicate.
	  What we do is to remove the second one.
	- If they are different, advance both pointers by one place.
	- Once the right pointer reaches the end, we are done.
*/