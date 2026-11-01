class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1) return 1;

        long long p = abs((long long)n);
        double ans = 1;

        while(p > 0) {
            if(p & 1) ans *= x;
            x *= x;
            p >>= 1;
        }

        return n < 0 ? 1 / ans : ans;
    }
};