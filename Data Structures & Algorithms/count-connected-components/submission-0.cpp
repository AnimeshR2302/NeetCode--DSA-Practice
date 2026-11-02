class Solution {
    int findpar(int i, vector<int>& parent) {
        if(parent[i] == i) return i;
        parent[i] = findpar(parent[i], parent);
        return parent[i];
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(),0);

        for(const auto& edge: edges) {
            int p0 = findpar(edge[0],parent);
            int p1 = findpar(edge[1],parent);

            parent[p1] = p0;
        }
        set<int> s;
        for(int& x: parent) s.insert(findpar(x, parent));
        return s.size();
    }
};
