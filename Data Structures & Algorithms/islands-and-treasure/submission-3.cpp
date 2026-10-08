class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++) for(int j = 0; j < grid[0].size(); j++)
            if(grid[i][j] == 0) q.push({i,j});

        array<int,4> dir = {-1,0,1,0};
        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int x = i + dir[k];
                int y = j + dir[3-k];

                if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] != INT_MAX) continue;

                grid[x][y] = grid[i][j] + 1;
                q.push({x,y});
            }
        }
    }
};