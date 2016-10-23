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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(vector<ListNode *>& lists, int lo, int hi) {
        if (lo == hi) return lists[lo];
        int mid = lo + (hi - lo) / 2;
        ListNode *lt = merge(lists, lo, mid);
        ListNode *rt = merge(lists, mid + 1, hi);
        ListNode head(0);
        ListNode *curr = &head;
        while (lt != nullptr && rt != nullptr) {
            if (lt->val < rt->val) {
                curr->next = lt;
                lt = lt->next;
            } else {
                curr->next = rt;
                rt = rt->next;
            }
            curr = curr->next;
        }
        if (lt != nullptr) curr->next = lt;
        else if (rt != nullptr) curr->next = rt;
        return head.next;
    }
}; // Author: XC

// Use priority queue, slow
class Solution {
public:
    struct compare {
        bool operator() (const ListNode* lhs, const ListNode* rhs) {
            return lhs->val > rhs->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto list : lists) {
            if (list != nullptr) pq.push(list);
        }
        ListNode prehead(0);
        ListNode* curr = &prehead;
        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next != nullptr) pq.push(curr->next);
        }
        return prehead.next;
    }
}; // Author: XC
