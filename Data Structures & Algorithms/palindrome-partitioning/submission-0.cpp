class Solution {
private:    
    static inline bool ispali(string s) {
        int i = -1, j = s.length();
        while(++i<--j) if(s[i] != s[j]) return false;
        return true;
    }

    void trav(int pos, string& s, vector<string>& cur, vector<vector<string>>& ans, vector<vector<int>>& pals) {
        if(pos == s.length()) {
            ans.emplace_back(cur);
            return;
        }
        for(int& x: pals[pos]) {
            cur.emplace_back(s.substr(pos,x));
            trav(pos+x,s,cur,ans,pals);
            cur.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> pals;
        vector<vector<string>> ans;
        vector<string> cur = {};

        for(int i=0;i<s.length();i++) {
            pals.emplace_back(vector<int>{});
            for(int j=1;j<=s.length()-i;j++) 
                if(ispali(s.substr(i,j))) pals[i].emplace_back(j);
        }

        trav(0,s,cur,ans,pals);

        return ans;
    }
};