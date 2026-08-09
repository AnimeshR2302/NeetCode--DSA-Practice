class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cur = 0, xmax = 0, start=0, end=0;
        string curstr = "";

        for(int i = 0;i<s.length();i++) {
            if(curstr.find(s[i]) == curstr.npos) {
                curstr += s[i];
                continue;
            }

            cur = i-start;
            xmax = max(xmax, cur);

            while(s[i] != s[start]) start++;
            curstr = s.substr(start+1, i-start);
            start++;
        }

        xmax = max(xmax, static_cast<int>(curstr.length())); 
        return xmax;
    }
};