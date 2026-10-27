class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};

        vector<vector<int>> ans;
        int s = 0;

        while(s < intervals.size() && newInterval[0] > intervals[s][1]) {
            ans.emplace_back(intervals[s]);
            s++;
        }

        while(s < intervals.size() && newInterval[1] >= intervals[s][0]) {
            newInterval[0] = min(newInterval[0], intervals[s][0]);
            newInterval[1] = max(newInterval[1], intervals[s][1]);
            s++;
        }

        ans.emplace_back(newInterval);
        while(s<intervals.size()) ans.emplace_back(intervals[s++]);

        return ans;
    }
};