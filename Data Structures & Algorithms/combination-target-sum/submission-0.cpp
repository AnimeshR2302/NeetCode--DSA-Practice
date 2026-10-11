class Solution {
private:
    void trav(int i, int& cur, int& target, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums) {
        temp.emplace_back(nums[i]);
        cur += nums[i];

        if(cur == target) {
            ans.emplace_back(temp);
        } else {
            for(int a=i;a<nums.size();a++) {
                if(cur + nums[a] > target) break;
                trav(a,cur,target,temp,ans,nums);
            }
        }

        cur -= nums[i];
        temp.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int cur = 0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++) {
            trav(i,cur,target,temp,ans,nums);
        }

        return ans;
    }
};
