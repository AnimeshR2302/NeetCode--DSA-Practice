class Solution {
private:
    void trav(int pos, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums, vector<bool>& vis) {
        vis[pos] = true;
        cur.emplace_back(nums[pos]);
        ans.emplace_back(cur);

        for(int i=pos+1;i<nums.size();i++) {
            trav(i,cur, ans,nums,vis);
        }

        vis[pos] = false;
        cur.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        vector<vector<int>> ans;
        
        vector<int> cur = {};
        ans.emplace_back(cur);

        for(int i=0;i<nums.size();i++) {
            trav(i,cur, ans, nums,vis);
        }

        return ans;
    }
};
