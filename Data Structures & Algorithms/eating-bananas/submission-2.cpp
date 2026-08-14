class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int low = 1, high = piles.back();

        while(low <= high) {
            int mid = low + (high - low) / 2;

            auto itr = upper_bound(piles.begin(), piles.end(), mid);
            int cnt = itr - piles.begin();

            while(itr != piles.end()) {
                int bananas = *itr;
                itr++;

                cnt += (bananas / mid);
                if(bananas % mid != 0) cnt++;

                if(cnt > h) {
                    low = mid + 1;
                    break;
                }
            }

            if(cnt <= h) high = mid - 1;
        }

        return low;
    }
};
