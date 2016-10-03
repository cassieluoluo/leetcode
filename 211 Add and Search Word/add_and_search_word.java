class TrieNode {
    public boolean isWord;
    public TrieNode[] arr;
    public TrieNode() {
        isWord = false;
        arr = new TrieNode[26];   
    }
}
public class WordDictionary {

    // Adds a word into the data structure.
    TrieNode root = new TrieNode();

    public void addWord(String word) {
        TrieNode curr = root;        
        for (char c : word.toCharArray()) {
            int index = c - 'a';
            
            if (curr.arr[index] == null) {
                TrieNode newNode = new TrieNode();
                curr.arr[index] = newNode;
            }
            curr = curr.arr[index];
        }
        curr.isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        return helper(word, root, 0);
    }
    private boolean helper(String word, TrieNode node, int index) {
        if (index == word.length()) {
            return node.isWord;
        }
        if (word.charAt(index) == '.') {
            for (TrieNode n : node.arr) {
                if (n != null && helper(word, n, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        int pos = word.charAt(index) - 'a';
        if (node.arr[pos] != null) {
            return helper(word, node.arr[pos], index + 1);
        }
        return false;
    }
} // Author: Cassie
