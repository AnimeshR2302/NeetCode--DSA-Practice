class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, ans = INT_MIN;

        for(int x : nums) {
            sum = max(x, sum + x);
            ans = max(ans, sum);
        }

        return ans;
    }
};