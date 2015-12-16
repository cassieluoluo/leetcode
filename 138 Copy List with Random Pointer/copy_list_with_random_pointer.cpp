/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) return head;
        unordered_map<RandomListNode*, RandomListNode*> memory;
        RandomListNode *curr = head->next;
        RandomListNode *head_cp = new RandomListNode(head->label);
        RandomListNode *curr_cp = head_cp;
        memory[head] = head_cp;
        while (curr != nullptr) {
            curr_cp->next = new RandomListNode(curr->label);
            curr_cp = curr_cp->next;
            memory[curr] = curr_cp;
            curr = curr->next;
        }
        curr = head;
        curr_cp = head_cp;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr_cp->random = memory[curr->random];
            }
            curr = curr->next;
            curr_cp = curr_cp->next;
        }
        return head_cp;
    }
};