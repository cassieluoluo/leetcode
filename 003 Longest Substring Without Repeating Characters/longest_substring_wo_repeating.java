// author: Bonnie

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int rtn = 0;
        int left = 0;
        for(int i=0; i<s.length(); i++){    
            char c = s.charAt(i);
            if(map.get(c)!=null){
                int last = map.get(c);
                left = Math.max(left, last+1);
            }
            map.put(c, i);
            rtn = Math.max(rtn, i-left+1);
        }
        return rtn;
    }
}
