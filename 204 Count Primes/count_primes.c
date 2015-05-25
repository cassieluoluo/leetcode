/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Count Primes
 *	https://leetcode.com/problems/count-primes/
 *	Runtime: 92 ms
 */
 
int countPrimes(int n) {
    if (n < 2) return 0;
	int *numbers = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) numbers[i] = 1;
	numbers[0] = 0;
	numbers[1] = 0;
	
	int p = 1;
	while (++p < sqrt(n))
		if (numbers[p] == 1)
			for (int i = p*p; i < n; i += p) numbers[i] = 0;

	int counter = 0;
	for (int i = 0; i < n; i++)
		if (numbers[i] == 1) counter++;

	return counter;
}