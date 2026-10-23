class Solution {
private:
    void trav(int pos, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums, vector<bool>& vis)  {
        cur.emplace_back(nums[pos]);

        if(cur.size() == nums.size()) ans.emplace_back(cur);
        else {
            vis[pos] = true;
            for(int i=0;i<nums.size();i++) {
                if(vis[i]) continue;
                trav(i,cur,ans,nums,vis);
            }
            vis[pos] = false;
        }

        cur.pop_back();
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> vis(nums.size(), false);
        vector<int> cur = {};

        for(int i=0;i<nums.size();i++) {
            trav(i,cur,ans,nums,vis);
        }

        return ans;
    }
};
