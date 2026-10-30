class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++) ans.emplace_back(bitset<1000>(i).count());
        return ans;
    }
};
