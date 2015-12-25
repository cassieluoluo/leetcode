public class Solution	// Author: Xinyu Chen
{
    private int k, n;
    private IList<IList<int>> result;
    public IList<IList<int>> CombinationSum3(int k, int n)
    {
        this.k = k;
        this.n = n;
        result = new List<IList<int>>();
        var row = new LinkedList<int>();
        dfs(n, k, 1, row);
        return result;
    }

    private void dfs(int sum, int count, int index, LinkedList<int> row)
    {
        if (count == 0 && sum != 0) return;
        if (sum == 0 && count != 0) return;
        if (sum == 0 && count == 0)
        {
            result.Add(new List<int>(row));
            return;
        }
        for (int i = index; i <= 9; ++i)
        {
            row.AddLast(i);
            dfs(sum - i, count - 1, i + 1, row);
            row.RemoveLast();
        }
    }
}
