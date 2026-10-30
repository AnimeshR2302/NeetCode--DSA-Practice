class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int tot = 0, ans = 0;

        for(int i=0;i<=nums.size();i++) tot ^= i;
        for(int i=0;i<nums.size();i++) ans ^= nums[i];

        return ans^tot;
    }
};