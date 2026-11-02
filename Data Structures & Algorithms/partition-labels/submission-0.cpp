class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length(), p1 = 0;
        unordered_map<int,int> fcnt;

        vector<int> cnt(26,0), ans = {n};
        for(const char& x: s) cnt[x-'a']++;

        for(int i=0;i<s.length();i++) {
            int pos = s[i] - 'a';

            if(fcnt.find(pos) == fcnt.end()) fcnt[pos] = 1; else fcnt[pos]++;
            if(fcnt[pos] == cnt[pos]) fcnt.erase(pos);

            if(fcnt.empty()) {
                int l = i - p1 + 1;
                p1 = i+1;

                if(l == ans.back()) break;
                
                swap(ans.back(), l);
                ans.emplace_back(l - ans.back());
            }
        }

        return ans;
    }
};