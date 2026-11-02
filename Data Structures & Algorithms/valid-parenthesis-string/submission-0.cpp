class Solution {
public:
    bool checkValidString(string s) {
        vector<int> pp, ss;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') pp.emplace_back(i);
            else if(s[i] == '*') ss.emplace_back(i);
            else if(!pp.empty()) pp.pop_back();
            else if(!ss.empty()) ss.pop_back();
            else return false;
        }

        while(!pp.empty()) {
            if(!ss.empty() && pp.back() < ss.back()) {
                ss.pop_back();
                pp.pop_back();
            } else return false;
        }

        return true;
    }
};