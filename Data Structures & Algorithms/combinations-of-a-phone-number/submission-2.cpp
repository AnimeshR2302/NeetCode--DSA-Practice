class Solution {
private:
    vector<char> num_letters(char digit) {
        int dig = (digit - '0') - 2;
        int num = (dig == 5 || dig == 7) ? 4 : 3;
        int adder =(dig > 5) ? 1: 0;
        vector<char> ret;

        for(int i=0;i<num;i++) {
            char c = 'a' + (3*dig + adder + i);
            ret.emplace_back(c);
        }

        return ret;
    }

    void myfun(int &digidx, string &digit, vector<string>& ans, string &cur) {
        if(digidx == digit.length()) {
            if(!cur.empty()) ans.emplace_back(cur);
            return;
        }

        auto myletters = num_letters(digit[digidx]);
        for(char x: myletters) {
            digidx++;
            cur.push_back(x);
            myfun(digidx, digit, ans, cur);
            cur.pop_back();
            digidx--;
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        string cur;
        vector<string> ans;
        int digx = 0;

        myfun(digx, digits, ans, cur);

        return ans;
    }
};