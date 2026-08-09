class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        int day = 0;
        stack<pair<int,int>> s;

        for(const auto &x: temperatures) {
            while(!s.empty() && x > s.top().first) {
                ans[s.top().second] = day - s.top().second;
                s.pop();
            }

            s.push({x,day++});
        }

        return ans;
    }
};