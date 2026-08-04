class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        unordered_map<char, char> mp = {
            {']', '['},
            {')', '('},
            {'}', '{'}
        };

        for(const auto &c: s) {
            if(mp.find(c) != mp.end()) {
                if(ss.empty()) return false;
                else if(mp[c] == ss.top()) ss.pop();
                else break;
            }
            else ss.push(c);
        }

        return ss.empty();
    }
};