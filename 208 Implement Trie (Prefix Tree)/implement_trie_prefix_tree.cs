class TrieNode	// Author: Xinyu Chen
{
    public const int NUM_LETTERS = 26;
    public bool isWord;
    public TrieNode[] children;
    // Initialize your data structure here.
    public TrieNode()
    {
        isWord = false;
        children = new TrieNode[NUM_LETTERS];
    }
}
public class Trie
{
    private TrieNode root;
    public Trie()
    {
        root = new TrieNode();
    }
    // Inserts a word into the trie.
    public void Insert(String word)
    {
        TrieNode node = root;
        foreach (var c in word)
        {
            int index = c - 'a';
            if (node.children[index] == null)
            {
                node.children[index] = new TrieNode();
            }
            node = node.children[index];
        }
        node.isWord = true;
    }
        // Returns if the word is in the trie.
    public bool Search(string word)
    {
        TrieNode node = root;
        foreach (var c in word)
        {
            int index = c - 'a';
            if (node.children[index] == null) return false;
            node = node.children[index];
        }
        return node.isWord;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public bool StartsWith(string word)
    {
        TrieNode node = root;
        foreach (var c in word)
        {
            int index = c - 'a';
            if (node.children[index] == null) return false;
            node = node.children[index];
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.Insert("somestring");
// trie.Search("key");