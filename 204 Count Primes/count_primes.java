/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Count Primes
 *	https://leetcode.com/problems/count-primes/
 *	Runtime: 288 ms
 */
 
public class Solution {
    public int countPrimes(int n) {
        if (n < 2) return 0;
        boolean[] numbers = new boolean[n];
        numbers[0] = false;
        numbers[1] = false;
        for (int i = 2; i < n; i++) numbers[i] = true;

        int p = 1;
        while (++p < Math.sqrt(n)) {
            if (numbers[p])
                for (int i = p*p; i < n; i += p) numbers[i] = false;
        }

        int counter = 0;
        for (boolean b : numbers)
            if (b) counter++;
        return counter;
    }
}