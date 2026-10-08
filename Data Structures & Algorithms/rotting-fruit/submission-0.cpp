class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> vis;
        int ans = 0, dir[4] = {-1,0,1,0}, fcnt = 0;
        
        for(int i=0;i<grid.size();i++) {
            vis.emplace_back(vector<bool>{});
            for(int j=0;j<grid[0].size();j++) {
                vis[i].emplace_back(true);

                if(grid[i][j] == 0) continue;
                else if(grid[i][j] == 2) q.push({i,j,0});
                else if(grid[i][j] == 1) {
                    fcnt++;
                    vis[i][j] = false;
                }
            }
        }

        if(fcnt == 0) return 0;
        cout<<fcnt<<"-"<<q.size()<<endl<<endl;
        while(!q.empty()) {
            auto [i,j,t] = q.front();
            q.pop();
            ans = max(ans, t);

            for(int k=0;k<4;k++) {
                int x = i + dir[k];
                int y = j+ dir[3-k];
                if(x<0 || y<0 || x>=grid.size() || y>= grid[0].size() || vis[x][y]) continue;
                
                vis[x][y] = true;
                q.push({x,y,t+1});
                fcnt--;

                if(fcnt == 0) return t+1;
            }
        }

        if(fcnt != 0) return -1;
        return ans;
    }
};
