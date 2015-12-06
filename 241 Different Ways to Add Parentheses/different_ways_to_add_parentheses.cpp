class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                string lt = input.substr(0, i);
                string rt = input.substr(i + 1);
                vector<int> lr = diffWaysToCompute(lt);
                vector<int> rr = diffWaysToCompute(rt);
                for (int l : lr) {
                    for (int r : rr) {
                        switch (c) {
                            case '+':
                                result.push_back(l + r);
                                break;
                            case '-':
                                result.push_back(l - r);
                                break;
                            case '*':
                                result.push_back(l * r);
                                break;
                        }
                    }
                }
            }
        }
        if (result.empty()) result.push_back(stoi(input));
        return result;
    }
};