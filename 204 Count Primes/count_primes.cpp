class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<int> numbers(n, 1);
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
}; // Author: XC
