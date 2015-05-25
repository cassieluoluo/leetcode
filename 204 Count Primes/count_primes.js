/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Count Primes
 *	https://leetcode.com/problems/count-primes/
 *	Runtime: 560 ms
 */

/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
    if (n < 2) return 0;
    var numbers = [];
    for (i = 2; i < n; i++) numbers[i] = true;
    
    var p = 0;
    while (++p < Math.sqrt(n)) {
        if (numbers[p])
            for (i = p*p; i < n; i += p) numbers[i] = false;
    }
    
    var counter = 0;
    for (i = 0; i < n; i++)
        if (numbers[i]) counter++;
    return counter;
};