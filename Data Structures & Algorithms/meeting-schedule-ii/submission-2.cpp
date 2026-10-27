class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const Interval& i1, const Interval& i2) {
            if(i1.start == i2.start) return i1.end > i2.end;
            return i1.start < i2.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        int cnt = 0;

        for(auto& x : intervals) {
            while(!pq.empty() && x.start >= pq.top())
                pq.pop();

            pq.push(x.end);
            cnt = max(cnt, (int)pq.size());
        }

        return cnt;
    }
};