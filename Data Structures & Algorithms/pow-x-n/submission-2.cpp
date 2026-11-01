class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;

        long long p = n;
        if(p < 0) {
            x = 1 / x;
            p = -p;
        }

        double ans = 1;

        while(p > 0) {
            if(p % 2) ans *= x;
            x *= x;
            p /= 2;
        }

        return ans;
    }
};