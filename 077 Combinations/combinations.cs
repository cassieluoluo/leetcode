public class Solution	// Author: Xinyu Chen
{
    private int n, k;
    private IList<IList<int>> result;
    public IList<IList<int>> Combine(int n, int k)
    {
        this.n = n;
        this.k = k;
        result = new List<IList<int>>();
        var row = new List<int>();
        dfs(1, row);
        return result;
    }
    private void dfs(int index, IList<int> row)
    {
        if (index > n) return;
        for (int i = index; i <= n; i++)
        {
            row.Add(i);
            if (row.Count == k)
            {
                result.Add(new List<int>(row));
            }
            else
            {
                dfs(i + 1, row);
            }
            row.RemoveAt(row.Count - 1);
        }
    }
}
