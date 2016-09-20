/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> arr;
        queue<TreeNode *> q;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node != nullptr) {
                arr.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
             } else {
                 arr.push_back("null");
             }
        }
        while (arr.size() > 0 && arr.back() == "null") arr.pop_back();
        stringstream ss;
        ss << "[";
        for (int i = 0; i < arr.size(); i++) {
            ss << arr[i];
            if (i != arr.size() - 1) ss << ",";
        }
        ss << "]";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data.substr(1, data.size() - 2));
        string item;
        while (getline(ss, item, ',')) {
            arr.push_back(item);
        }
        if (arr.empty()) return nullptr;
        vector<TreeNode *> nodes;
        for (auto s : arr) {
            if (s == "null") nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(stoi(s)));
        }
        TreeNode *root = nodes[0];
        int pos = 0;
        for (int i = 1; i < nodes.size(); i++) {
            while (nodes[pos] == nullptr) { pos++; }
            if (i % 2 == 1) {
                nodes[pos]->left = nodes[i];
            } else {
                nodes[pos]->right = nodes[i];
                pos++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// Author: XC
