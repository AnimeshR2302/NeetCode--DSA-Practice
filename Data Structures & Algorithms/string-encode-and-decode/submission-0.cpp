class Solution {
public:
    string encode(vector<string>& strs) {
        string endstr = "s", split = "#";
        string ans = "";

        for(auto &st: strs) {
            for(auto &c: st) {
                ans += to_string(static_cast<int>(c));
                ans += split;
                if(ans.length()<=10) cout<<ans<<endl;
            }
            ans += endstr;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string cur;
        int num = 0;

        for(auto c: s) {
            if(c=='s') {
                ans.emplace_back(cur);
                cur.clear();
            } else if (c=='#') {
                cur += static_cast<char>(num);
                num = 0;
            } else {
                num = num * 10 + (c-'0');
            } 
        }

        return ans;
    }
};