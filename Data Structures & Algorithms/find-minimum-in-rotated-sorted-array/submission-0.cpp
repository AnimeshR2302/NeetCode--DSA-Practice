class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        int ans = nums.back();

        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > ans) low = mid + 1;
            else { 
                ans = nums[mid];
                high = mid;
            }
        }

        return nums[low];
    }
};
