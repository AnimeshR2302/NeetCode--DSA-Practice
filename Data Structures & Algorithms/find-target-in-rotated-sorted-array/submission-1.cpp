class Solution {
private:
    int rotated(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }

        return low;
    }
public:
    int search(vector<int>& nums, int target) {
        int r = rotated(nums);
        int n = nums.size(), low = 0, high = n - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            int pos = (mid + r) % n;

            if(nums[pos] == target) return pos;
            else if(nums[pos] < target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
};