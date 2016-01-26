/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  // Author: Xinyu Chen
public:
    ListNode* swapPairs(ListNode* head) {
       if (head == nullptr || head->next == nullptr) return head;
    	ListNode *prev, *left, *right, *next;
    	ListNode *prehead = new ListNode(0);
    	prehead->next = head;
    	prev = prehead;
    	left = head;
    	right = head->next;
    	while (right != nullptr) {
    		next = right->next;
    		right->next = left;
    		left->next = next;
    		prev->next = right;
    
    		prev = prev->next->next;
    		left = left->next;
    		if (left == nullptr) break;
    		right = left->next;
    	}
    	return prehead->next;
    }
};
