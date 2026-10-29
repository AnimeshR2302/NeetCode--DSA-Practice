class Solution {
private:
    unordered_map<int,int> dp = {
        {1,1},
        {2,2},
        {3,3}
    };

public:
    int climbStairs(int n) {
        if(dp.find(n) == dp.end()) dp[n] = climbStairs(n-2) + climbStairs(n-1);
        return dp[n];
    }
};
