class TrieNode	// Author: Xinyu Chen
{
    public const int NUM_LETTERS = 26;
    public bool isWord;
    public TrieNode[] children;
    public TrieNode()
    {
        isWord = false;
        children = new TrieNode[NUM_LETTERS];
    }
}
class Trie
{
    private TrieNode root;
    public Trie()
    {
        root = new TrieNode();
    }

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

public class Solution
   {
	private IList<string> result;
	private char[,] board;
	private Trie trie;
	private int rows, cols;
	public IList<string> FindWords(char[,] board, string[] words)
	{
	    trie = new Trie();
	    rows = board.GetLength(0);
	    cols = board.GetLength(1);
	    this.board = new char[rows, cols];
	    for (var i = 0; i < rows; ++i)
	    {
		for (var j = 0; j < cols; ++j)
		{
		    this.board[i, j] = board[i, j];
		}
	    }
	    foreach (var s in words)
	    {
		trie.Insert(s);
	    }
	    result = new List<string>();
	    string str = "";
	    for (var row = 0; row < rows; ++row)
	    {
		for (var col = 0; col < cols; ++col)
		{
		    dfs(row, col, str);
		}
	    }
	    return result.Distinct().ToList();
	}

	private void dfs(int row, int col, String word)
	{
	    if (row < 0 || row >= rows || col < 0 || col >= cols) return;
	    char c = board[row, col];
	    if (c == '.') return;
	    board[row, col] = '.';
	    string current = word + c;
	    if (!trie.StartsWith(current))
	    {
		    board[row, col] = c;
		    return;
	    }
	    if (trie.Search(current))
	    {
		    result.Add(current);
	    }
	    dfs(row - 1, col, current);
	    dfs(row, col - 1, current);
	    dfs(row + 1, col, current);
	    dfs(row, col + 1, current);
	    board[row, col] = c;
	}
}
