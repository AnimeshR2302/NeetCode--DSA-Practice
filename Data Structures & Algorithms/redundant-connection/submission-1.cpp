class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> par(edges.size() + 1), ans;
        iota(par.begin(),par.end(),0);

        auto findpar = [&](auto&& self,int i) -> int {
            if(par[i] != i) par[i] = self(self,par[i]);
            return par[i];
        };

        ans.reserve(2);
        for(const auto& edge: edges) {
            int p0 = findpar(findpar, edge[0]);
            int p1 = findpar(findpar, edge[1]);
            
            if(p0 == p1) {
                ans = edge;
                break;
            }
            par[p1] = p0;
        }
        return ans;
    }
};