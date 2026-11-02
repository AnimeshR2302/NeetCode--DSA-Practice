class Solution {
    int findpar(int i, vector<int>& parent) {
        if(parent[i] == i) return i;
        parent[i] = findpar(parent[i], parent);
        return parent[i];
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int groups = n;
        vector<int> parent(n);
        iota(parent.begin(), parent.end(),0);

        for(const auto& edge: edges) {
            int p0 = findpar(edge[0],parent);
            int p1 = findpar(edge[1],parent);

            if(p0 != p1){
                parent[p1] = p0;
                groups--;
            }
        }
        return groups;
    }
};
