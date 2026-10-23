class Solution {
private:
    void trav(int pos, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums) {
        vector<bool> vis(41, false);

        cur.emplace_back(nums[pos]);
        ans.emplace_back(cur);

        for(int i=pos+1;i<nums.size();i++) {
            int vpos = nums[i] + 20;
            if(vis[vpos]) continue;

            vis[vpos] = true;
            trav(i,cur, ans, nums);
        }

        cur.pop_back();
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur = {};
        vector<bool> vis(41, false);

        ans.emplace_back(cur);

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++) {
            int vpos = nums[i] + 20;
            if(vis[vpos]) continue;

            vis[vpos] = true;
            trav(i,cur, ans, nums);
        }

        return ans;
    }
};
