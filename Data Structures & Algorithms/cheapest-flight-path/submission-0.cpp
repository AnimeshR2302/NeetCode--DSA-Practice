class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& f : flights) adj[f[0]].emplace_back(f[1], f[2]);

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,greater<>> pq;

        pq.push({0, src, 0});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, node, steps] = pq.top();
            pq.pop();

            if (node == dst) return cost;
            else if (cost > dist[node][steps] || steps == k+1)  continue;

            for (const auto& [next, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < dist[next][steps + 1]) {
                    dist[next][steps + 1] = newCost;
                    pq.push({newCost, next, steps + 1});
                }
            }
        }

        return -1;
    }
};
