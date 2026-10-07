class Solution {
private:
    int side[4] = {-1,0,1,0};

    void trav(int i ,int j , int& rows, int& cols, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        if(i < 0 || i >= rows || j < 0 || j>=cols || grid[i][j] == '0' || vis[i][j]) return;
        cout<<i<<"-"<<j<<endl;
        vis[i][j] = true;

        for(int r=0;r<4;r++) trav(i + side[r],j+side[3-r],rows,cols,vis,grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for(int i = 0; i<rows;i++) {
            for(int j=0; j<cols;j++) {
                if(grid[i][j] == '0' || vis[i][j]) continue;
                else {
                    trav(i,j,rows,cols, vis, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};
