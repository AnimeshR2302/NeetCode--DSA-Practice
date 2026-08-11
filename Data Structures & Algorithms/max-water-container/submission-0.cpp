class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1, ans = 0;
        
        while(p1 < p2) {
            ans = max(ans, ((p2 - p1) * min(height[p2], height[p1])));

            if(height[p1] < height[p2]) p1++; else p2--;
        }

        return ans;
    }
};