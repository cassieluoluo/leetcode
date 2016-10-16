/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if (!root) return;
    root->next = NULL;
    struct TreeLinkNode *parent, *first, *second;
    parent = root;
    while (parent) {
        first = second = NULL;
        while (parent) {
            if (parent->left) {
                if (!first) {
                    first = parent->left;
                    second = first;
                } else {
                    second->next = parent->left;
                    second = second->next;
                }
            }
            if (parent->right) {
                if (!first) {
                    first = parent->right;
                    second = first;
                } else {
                    second->next = parent->right;
                    second = second->next;
                }
            }
            parent = parent->next;
        }
        parent = first;
    }
}   // Author: XC
