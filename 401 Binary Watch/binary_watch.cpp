class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (__builtin_popcount(h) + __builtin_popcount(m) != num) continue;
                string timestr = to_string(h);
                timestr += ":";
                if (m < 10) timestr += "0";
                timestr += to_string(m);
                result.push_back(timestr);
            }
        }
        return result;
    }
}; // Author: XC
