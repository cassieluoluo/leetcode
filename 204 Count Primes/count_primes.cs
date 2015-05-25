/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Count Primes
 *	https://leetcode.com/problems/count-primes/
 *	Runtime: 132 ms
 */

public class Solution {
    public int CountPrimes(int n) {
        if (n < 2) return 0;
        bool[] numbers = new bool[n];
        for (int i = 0; i < n; i++) numbers[i] = true;
        numbers[0] = false;
        numbers[1] = false;
        int p = 1;
        while (++p < Math.Sqrt(n))
        {
            if (!numbers[p]) continue;
            for (int i = p*p; i < n; i += p) numbers[i] = false;
        }
        return numbers.Count(b => b);
    }
}