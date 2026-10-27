class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& v1,  const vector<int>& v2) {
            if(v1.back()==v2.back()) return v1.front() > v2.front();
            return v1.back() < v2.back();
        });

        int cnt = -1, start = intervals[0].front(), end = intervals[0].back();
        
        for(auto &x: intervals) {
            if(x.front()>=end) end = x.back();
            else cnt++;
        }

        return cnt;   
    }
};