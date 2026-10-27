class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        queue<vector<int>> q;

        for(int i=0;i<intervals.size();i++) {
            q.push({intervals[i]});
            while(!q.empty()) {
                if(ans.empty()) {
                    ans.emplace_back(q.front());
                    q.pop();
                }
                else if(ans.back().back() < q.front().front()) break;
                else if(ans.back().front() > q.front().back()) {
                    q.push(ans.back());
                    ans.pop_back();
                } else {
                    auto a = min(ans.back().front(),q.front().front());
                    auto b = max(ans.back().back(),q.front().back());
                    
                    ans.pop_back();
                    q.pop();
                    q.push(vector<int>{a,b});
                }
            }
            while(!q.empty()) {
                ans.emplace_back(q.front());
                q.pop();
            }
        }

        return ans;
    }
};
