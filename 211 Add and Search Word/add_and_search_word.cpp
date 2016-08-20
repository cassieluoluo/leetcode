class DictNode {
public:
    bool is_word;
    DictNode *children[26];
    DictNode() {
        is_word = false;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        DictNode *curr = &root;
        for (auto c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new DictNode();
            }
            curr = curr->children[index];
        }
        curr->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, 0, &root);
    }
    
    bool dfs(const string& word, int pos, DictNode *node) {
        if (pos == word.size()) return node->is_word;
        bool res = false;
        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] == nullptr) continue;
                res |= dfs(word, pos + 1, node->children[i]);
                if (res) return true;
            }
            return false;
        }
        int index = word[pos] - 'a';
        if (node->children[index] == nullptr) return false;
        return dfs(word, pos + 1, node->children[index]);
    }
private:
    DictNode root;
}; // Author: XC

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");