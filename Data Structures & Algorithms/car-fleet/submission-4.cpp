class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,float>> pq;

        for(int i = 0;i<position.size();i++) {
            int dist = target - position[i];
            auto time = static_cast<float>(dist) / speed[i];
            
            pq.push({dist, time});
        }

        vector<float> v;
        while(!pq.empty()) {
            while(!v.empty() && v.back() <= pq.top().second) v.pop_back();
            v.emplace_back(pq.top().second);
            pq.pop();
        }

        return v.size();
    }
};