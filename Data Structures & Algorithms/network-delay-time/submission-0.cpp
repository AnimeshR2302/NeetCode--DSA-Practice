class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(const vector<int>& edge: times)
            adj[edge[0]].emplace_back(edge[1], edge[2]);

        vector<int> dij(n+1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        pq.push({0, k});

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if(time < dij[node]) {
                dij[node] = time;
                for(const auto& [nextNode, nextTime] : adj[node])
                    pq.push({time + nextTime, nextNode});
            }
        }

        int ans = 0;
        dij[0] = -1;
        for(const int& x: dij)
            if(x == INT_MAX) return -1; else ans = max(ans, x);

        return ans;
    }
};