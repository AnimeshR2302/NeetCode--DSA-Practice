class Solution {
public:
    vector<int> countBits(int n) {
        int pval = 1;
        vector<int> ans= {0};

        for(int i=1;i<=n;i++)
            if(i==pval*2) {
                pval *= 2;
                ans.emplace_back(1);
            } else ans.emplace_back(ans[i-pval]+1);

        return ans;
    }
};
