class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size(), lhalf = (m + n + 1) / 2;
        int low = 0, high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int remlen = lhalf - mid;

            int L1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int R1 = (mid == m) ? INT_MAX : nums1[mid];
            int L2 = (remlen == 0) ? INT_MIN : nums2[remlen - 1];
            int R2 = (remlen == n) ? INT_MAX : nums2[remlen];

            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 == 1) return max(L1, L2);

                return (
                    (long long)max(L1, L2) +
                    min(R1, R2)
                ) / 2.0;
            } else if (L1 > R2) high = mid - 1;
            else  low = mid + 1;
        }

        return 0.0;
    }
};