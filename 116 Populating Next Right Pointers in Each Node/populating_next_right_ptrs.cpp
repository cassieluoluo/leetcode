/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeLinkNode *first, *second;
            first = q.front();
            q.pop();
            if (first->left != nullptr) q.push(first->left);
            if (first->right != nullptr) q.push(first->right);
            for (int i = 1; i < n; i++) {
                second = q.front();
                q.pop();
                if (second->left != nullptr) q.push(second->left);
                if (second->right != nullptr) q.push(second->right);
                first->next = second;
                first = second;
            }
            first->next = nullptr;
        }
    }

    void connect(TreeLinkNode *root) { // O(1) space
        if (root == nullptr) return;
        if (root->left != nullptr) root->left->next = root->right;
        if (root->right != nullptr && root->next != nullptr) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
}; // Author: XC
