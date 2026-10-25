class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> qp, qa;

        for(int i = 0; i < m; i++) {
            pac[i][0] = atl[i][n - 1] = true;
            qp.push({i, 0});
            qa.push({i, n - 1});
        }

        for(int j = 0; j < n; j++) {
            pac[0][j] = atl[m - 1][j] = true;
            qp.push({0, j});
            qa.push({m - 1, j});
        }

        const int dir[5] = {-1, 0, 1, 0, -1};

        auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& vis) {
            while(!q.empty()) {
                auto [i, j] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int x = i + dir[k];
                    int y = j + dir[k + 1];

                    if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || heights[x][y] < heights[i][j])
                        continue;

                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        };

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> ans;

        for(int i = 0; i < m; i++) for(int j = 0; j < n; j++)
            if(pac[i][j] && atl[i][j]) ans.push_back({i, j});

        return ans;
    }
};