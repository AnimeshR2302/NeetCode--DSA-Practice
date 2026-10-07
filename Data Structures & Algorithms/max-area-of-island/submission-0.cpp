class Solution {
private:
    static inline constexpr array<int,4> side = {-1,0,1,0};

    void trav(int i ,int j , int& rows, int& cols, vector<vector<bool>>& vis, vector<vector<int>>& grid, int& cur) {
        if(i < 0 || i >= rows || j < 0 || j>=cols || grid[i][j] == 0 || vis[i][j]) return;
        vis[i][j] = true;
        cur++;

        for(int r=0;r<4;r++) trav(i + side[r],j+side[3-r],rows,cols,vis,grid, cur);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i<rows;i++) {
            for(int j=0; j<cols;j++) {
                if(grid[i][j] == 0 || vis[i][j]) continue;
                else {
                    int cur = 0;
                    trav(i,j,rows,cols, vis, grid, cur);
                    ans = max(ans, cur);
                }
            }
        }

        return ans;
    }
};

