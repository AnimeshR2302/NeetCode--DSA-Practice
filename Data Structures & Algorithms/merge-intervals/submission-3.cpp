class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < intervals.size(); i++) {
            if(ans.empty() || ans.back().back() < intervals[i].front()) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back().back() = max(ans.back().back(), intervals[i].back());
            }
        }

        return ans;
    }
};