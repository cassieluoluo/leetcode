// Author: Yifan Zhou
// Given a string which contains only lowercase letters,
// remove duplicate letters so that every letter appear once 
// and only once. You must make sure your result is the smallest
// in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int counts[256]={0};
        string result="";
        bool added[256]={false};
        int N_s=s.length();
        for(int i=0;i<N_s;i++){
            counts[s[i]]++;
        }
        result+=1;
        for(int i=0;i<N_s;i++){
            counts[s[i]]--;
            if(added[s[i]])continue;
            while( counts[result.back()] && result.back()>s[i]){
                added[result.back()]=false;
                result.pop_back();
            };
            added[s[i]]=true;
            result.push_back(s[i]);
        }
        return result.substr(1);
    }
};