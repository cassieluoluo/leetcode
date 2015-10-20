/*	
 *	LeetCode Submissions by Xinyu Chen
 *	Fraction to Recurring Decimal
 *	https://leetcode.com/problems/fraction-to-recurring-decimal/
 *	Runtime: 0 ms
 */

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	long long num = numerator;
    	long long den = denominator;
    	int pos = 0;
    	bool repeat = false;
    	bool negative = false;
    	vector<int> buffer;
    	stringstream result;
    	if (num < 0) {
    		negative = !negative;
    		num = -num;
    	}
    	if (den < 0) {
    		negative = !negative;
    		den = -den;
    	}
    	if (negative && num != 0) result << '-';
    	long long q = num / den;
    	long long r = num % den;
    	result << q;
    	if (r == 0) return result.str();
    	result << '.';
    	unordered_map<long long, int> rems;
    	while (r != 0) {
    		if (rems.find(r) == rems.end()) {
    			rems[r] = pos++;
    			r *= 10;
    			q = r / den;
    			r = r % den;
    			buffer.push_back(q);
    		}
    		else {
    			pos = rems[r];
    			repeat = true;
    			break;
    		}
    	}
    	if (repeat) {
    		for (int i = 0; i < pos; i++) result << buffer[i];
    		result << '(';
    		for (unsigned int i = pos; i < buffer.size(); i++) result << buffer[i];
    		result << ')';
    	}
    	else {
    		for (auto val : buffer) result << val;
    	}
    	return result.str();
    }
};