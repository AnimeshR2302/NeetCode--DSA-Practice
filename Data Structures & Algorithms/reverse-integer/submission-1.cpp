class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) x++;
        int ans=0;
        bool isNeg = x < 0;
        if(isNeg) x*= -1;

        while(x) {
            if(ans > (INT_MAX - (x%10)) / 10) return 0;

            ans *= 10;
            ans += x%10;
            x/=10;
        }

        if(isNeg) ans*=-1;
        return ans;
    }
};