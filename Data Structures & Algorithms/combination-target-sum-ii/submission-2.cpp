class Solution {
private:
    void trav(int pos, int& target, vector<int>& cur, set<vector<int>>& s, vector<int>& nums) {
        if(target - nums[pos] < 0) return;

        vector<bool> vis(51,false);
        cur.emplace_back(nums[pos]);

        if(target - nums[pos] == 0) s.insert(cur);
        else {
            target -= nums[pos];
            for(int i=pos+1;i<nums.size();i++) {
                int c = nums[i];
                
                if(c > target) break;
                if(vis[c]) continue;

                vis[c] = true;
                trav(i,target,cur,s,nums);
            }
            target += nums[pos];
        }

        cur.pop_back();
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> s;
        vector<int> cur = {};
        vector<bool> vis(51,false);

        sort(candidates.begin(),candidates.end());

        for(int i=0;i<candidates.size();i++) {
            int c = candidates[i];
            
            if(c > target) break;
            if(vis[c]) continue;

            vis[c] = true;
            trav(i,target,cur,s,candidates);
        }

        vector<vector<int>> ans;
        for(auto itr = s.begin();itr!= s.end();itr++) ans.emplace_back(*itr);

        return ans;
    }
};
