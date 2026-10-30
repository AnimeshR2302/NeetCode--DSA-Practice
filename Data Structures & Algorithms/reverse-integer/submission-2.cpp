class Solution {
public:
    int reverse(int x) {
        int ans=0;

        while(x) {
            int rem = x%10;
            x/=10;

            if(ans> INT_MAX/10 || ans < INT_MIN/10) return 0; else ans*=10;
            if(ans+rem > INT_MAX || ans+rem < INT_MIN) return 0; else ans+=rem;
        }

        return ans;
    }
};