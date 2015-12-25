class DictNode	// Author: Xinyu Chen
{
    public const int NUM_LETTERS = 26;
    public bool isWord;
    public DictNode[] children;
    
    public DictNode()
    {
        isWord = false;
        children = new DictNode[NUM_LETTERS];
    }
}
public class WordDictionary
{
    private DictNode root;
    public WordDictionary()
    {
        root = new DictNode();
    }
    // Adds a word into the data structure.
    public void AddWord(String word)
    {
        DictNode node = root;
        foreach (var c in word)
        {
            int index = c - 'a';
            if (node.children[index] == null)
            {
                node.children[index] = new DictNode();
            }
            node = node.children[index];
        }
        node.isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public bool Search(string word)
    {
        return search(word, 0, root);
    }
    private bool search(string word, int pos, DictNode node)
    {
        if (pos == word.Length) return node.isWord;
        if (word[pos] == '.')
        {
            foreach (var n in node.children)
            {
                if (n == null) continue;
                if (search(word, pos + 1, n)) return true;
            }
            return false;
        }
        int index = word[pos] - 'a';
        if (node.children[index] == null) return false;
        return search(word, pos + 1, node.children[index]);
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.AddWord("word");
// wordDictionary.Search("pattern");