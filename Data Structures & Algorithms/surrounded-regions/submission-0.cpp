class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size(), dir[4] = {-1,0,1,0};

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> q, rest;

        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(board[i][j] == 'X') vis[i][j] = true;
            else if(i==0 || i == n-1 || j == 0 || j== m-1) q.push({i,j}); 
            else rest.push({i,j});

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
            vis[i][j] = true;

            for(int d=0;d<4;d++) {
                int x = i+dir[d];
                int y = j+dir[3-d];

                if(x<0 || y<0 || x>=n || y>= m || vis[x][y]) continue;
                q.push({x,y});
            }
        }

        while(!rest.empty()) {
            auto [i,j] = rest.front();
            rest.pop();
            if(!vis[i][j]) board[i][j] = 'X';
        }
    }
};
