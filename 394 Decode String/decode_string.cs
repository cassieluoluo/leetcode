public class Solution {
    public string DecodeString(string s) {
        var stackNum = new Stack<int>();
        var stackSb = new Stack<StringBuilder>();
        var sb = new StringBuilder();
        int num = 0;
        foreach (var c in s) {
            if ('0' <= c && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                stackNum.Push(num);
                num = 0;
                stackSb.Push(sb);
                sb = new StringBuilder();
            } else if (c == ']') {
                num = stackNum.Pop();
                string str = sb.ToString();
                sb = stackSb.Pop();
                for (int i = 0; i < num; i++) sb.Append(str);
                num = 0;
            } else {
                sb.Append(c);
            }
        }
        return sb.ToString();
    }
} // Author: XC
