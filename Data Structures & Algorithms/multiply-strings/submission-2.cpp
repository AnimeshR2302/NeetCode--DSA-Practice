class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        vector<int> v(l1+l2+1, 0);

        for(int i=0;i<l1;i++) for(int j=0;j<l2;j++) {
            int cur = (num1[l1-i-1] - '0') * (num2[l2-j-1] - '0');
            int start = l1+l2 - i - j;

            while(cur) {
                v[start] += cur%10;
                cur /= 10;

                cur += v[start]/10;
                v[start] %= 10;
                start--;
            }
        }

        string ans;
        for(int &x: v) {
            if(ans.empty() && x==0) continue;
            ans += '0'+x;
        }

        return ans.empty() ? "0" : ans;
    }
};