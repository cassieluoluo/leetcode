class Solution {	// Author: Xinyu Chen
public:
    string intToRoman(int num) {
        stringstream ss;
        
        while (num >= 1000) {
            ss << 'M';
            num -= 1000;
        }
        
        if (num >= 900) {
            ss << "CM";
            num -= 900;
        }
        if (num >= 500) {
            ss << 'D';
            num -= 500;
        }
        if (num >= 400) {
            ss << "CD";
            num -= 400;
        }
        while (num >= 100) {
            ss << 'C';
            num -= 100;
        }
        
        if (num >= 90) {
            ss << "XC";
            num -= 90;
        }
        if (num >= 50) {
            ss << 'L';
            num -= 50;
        }
        if (num >= 40) {
            ss << "XL";
            num -= 40;
        }
        while (num >= 10) {
            ss << 'X';
            num -= 10;
        }
        
        if (num == 9) {
            ss << "IX";
            num -= 9;
        }
        if (num >= 5) {
            ss << 'V';
            num -= 5;
        }
        if (num == 4) {
            ss << "IV";
            num -= 4;
        }
        while (num >= 1) {
            ss << 'I';
            num--;
        }
        return ss.str();
    }
};
