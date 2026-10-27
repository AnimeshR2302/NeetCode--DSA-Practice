/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const Interval& i1, const Interval& i2){
            if(i1.start == i2.start) return i1.end < i2.end;
            return i1.start < i2.start;
        });
        int e=INT_MIN;

        for(auto &x: intervals) {
            if(x.start < e) return false;
            e = x.end;
        }
        return true;
    }
};
