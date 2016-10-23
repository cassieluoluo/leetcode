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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *curr = head;
        int count = 0, value = 0;
        while (curr != nullptr) {
            int r = rand() % (count + 1);
            if (r == 0) value = curr->val;
            curr = curr->next;
            ++count;
        }
        return value;
    }

private:
    ListNode *head;
}; // Author: XC

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
