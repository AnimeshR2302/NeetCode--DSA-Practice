class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        for(int idx = 0; const char& x: s) last[x] = idx++;

        int part = 0;
        vector<int> ans;

        for(int i=0, xsize=1;i<s.length();i++, xsize++) {
            part = max(part, last[s[i]]);
            if(i==part) {
                ans.emplace_back(xsize);
                xsize = 0;
            }
        }

        return ans;
    }
};