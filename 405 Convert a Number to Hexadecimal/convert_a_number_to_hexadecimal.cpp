class Solution {
public:
    string toHex(int num) {
        string res;
        while (num > 0 && res.size() < 8) {
            res = hex[num % 16] + res;
            num /= 16;
        }
        return res;
    }

private:
    char hex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
}; // Author: XC
