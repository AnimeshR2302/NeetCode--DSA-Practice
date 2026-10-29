class Solution {
private:
    pair<int,int> trav(int n, vector<int>& nums) {
        if(n == 0) return {nums[0],0};

        auto[p1, p2] = trav(n-1,nums);
        return {max(nums[n] + p2, p1), p1};
    }
public:
    int rob(vector<int>& nums) {
        auto[p1,p2] =  trav(nums.size()-1, nums);
        return max(p1,p2);
    }
};
