class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;

        auto swap_inc_switch = [&](bool &isOdd, int& start, int& end) {
            if(isOdd) end++; else start--;
            isOdd = !isOdd;
        };

        for(int i = 0; i < n; i++) {
            int start = i, end = i;
            bool isOdd = true;
            bool oddValid = true, evenValid = true;

            while(start >= 0 && end < n && (oddValid || evenValid)) {
                if(isOdd ? oddValid : evenValid) {
                    if(s[start] == s[end]) cnt++;
                    else if(isOdd) oddValid = false;
                    else evenValid = false;
                }

                swap_inc_switch(isOdd, start, end);
                if((isOdd && !oddValid) || (!isOdd && !evenValid))
                    swap_inc_switch(isOdd, start, end);
            }
        }

        return cnt;
    }
};