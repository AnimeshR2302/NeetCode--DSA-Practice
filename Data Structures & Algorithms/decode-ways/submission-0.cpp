class Solution {
public:
    int numDecodings(string s) {
        int cnt = 0, n = s.length();
        vector<int> v(n,0);

        for(int i=0;i<n;i++) {
            if(s[i] == '0') continue;
            int num = 0;

            for(int j=0;j<2 && i+j<n;j++) {
                num = num*10;
                num += (s[i+j] - '0');
                if(num>0 && num<27) if(i == 0) v[i+j]++; else v[i+j] += v[i-1];
            }
        }

        return v[n - 1];
    }
};