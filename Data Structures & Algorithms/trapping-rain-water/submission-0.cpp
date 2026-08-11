class Solution {
public:
    int trap(vector<int>& height) {
        int p1,p2,lmax,rmax,ans;
        
        p1 = ans = lmax = rmax = 0;
        p2 = height.size() - 1;

        while(p1 < p2) {
            if(height[p1] < lmax) ans += lmax - height[p1];
            else lmax = height[p1];
            
            if(height[p2] < rmax) ans += rmax - height[p2];
            else rmax = height[p2];

            if(lmax < rmax) p1++; else p2--;
        }

        return ans;
    }
};