class Solution {
public:
    bool checkNumber(string& num, int first, int second) {
    	if (second != 1 && num[first] == '0') return false;
    	unsigned long long a = stoi(num.substr(0, first));
    	unsigned long long b = stoi(num.substr(first, second));
    	unsigned long long s = a + b;
    	
    	for (int start = first + second; start < num.size();) {
    		string sum = to_string(s);
    		for (int i = 0; i < sum.size(); i++) {
    			if (sum[i] != num[start + i]) return false;
    		}
    		a = b;
    		b = s;
    		s = a + b;
    		start += to_string(b).size();
    	}
    	return true;
    }
    
    bool isAdditiveNumber(string num) {
    	for (int i = 1; i <= num.size() / 2; i++) {
    		for (int j = 1; max(i, j) + i + j <= num.size(); j++) {
    			if (i == 2 && j == 2)
    				i = i;
    			if (checkNumber(num, i, j)) return true;
    		}
    	}
    	return false;
    }
}; // Author: XC
