class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        auto solve = [&](int l, int r) {
            int prev1 = 0, prev2 = 0;

            for(int i = l; i <= r; i++) {
                int cur = max(prev1, nums[i] + prev2);
                prev2 = prev1;
                prev1 = cur;
            }
            return prev1;
        };

        return max(solve(0, n-2), solve(1, n-1));
    }
};