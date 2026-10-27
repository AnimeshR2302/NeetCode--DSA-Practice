class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            in[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (in[i] == 0) q.push(i);

        vector<int> ans;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.emplace_back(cur);

            for (int next : adj[cur]) if (--in[next] == 0) q.push(next);
        }

        if(ans.size() == numCourses) return ans;
        return {};
    }
};