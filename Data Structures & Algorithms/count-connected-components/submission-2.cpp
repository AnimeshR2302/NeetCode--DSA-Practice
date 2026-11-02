class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int groups = n;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(),0);

        auto findpar = [&](auto&& self, int i) {
            if(parent[i] == i) return i;
            parent[i] = self(self, parent[i]);
            return parent[i];
        };

        for(const auto& edge: edges) {
            int p0 = findpar(findpar,edge[0]);
            int p1 = findpar(findpar,edge[1]);

            if(p0 != p1){
                parent[p1] = p0;
                groups--;
            }
        }
        return groups;
    }
};
