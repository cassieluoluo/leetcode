class Solution {
public:
    string numberToWords(int num) {
        return convert(num, 0);
    }

private:
    string convert(int num, int count) {
		if (num == 0) return count == 0 ? "Zero" : "";
        int value = num % 1000;
		stringstream ss;
		int hundred = value / 100;
		if (hundred > 0) ss << digit[hundred] << " Hundred";
		int t = value % 100;
		if (t == 0) {
			// Do nothing
		} else if (t < 10) {
			if (ss.tellp() > 0) ss << " ";
			ss << digit[t];
		} else if (t < 20) {
			if (ss.tellp() > 0) ss << " ";
			ss  << special[t - 10];
		}
		else {
			if (ss.tellp() > 0) ss << " ";
			ss << tens[t / 10];
			if (t % 10 > 0) ss << " " << digit[t % 10];
		}
		if (count > 0) ss << " ";
		ss << unit[count];
        string extra = convert(num / 1000, count + 1);
        if (extra != "" && value != 0) return extra + " " + ss.str();
        if (extra != "") return extra;
		return ss.str();
    }
    const vector<string> unit{"", "Thousand", "Million", "Billion", "Trillion",};
    const vector<string> digit{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> special{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
}; // Author: XC
