class Solution {
private:
    void trav(string& cur, int n, int tot, vector<string>& ans) {
        if (tot == 0) {
            ans.emplace_back(cur);
            return;
        }

        if (n > 0) {
            cur.push_back('(');
            trav(cur, n - 1, tot - 1, ans);
            cur.pop_back();
        }

        if (tot - n > n) {
            cur.push_back(')');
            trav(cur, n, tot - 1, ans);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;

        trav(cur, n, 2 * n, ans);

        return ans;
    }
};