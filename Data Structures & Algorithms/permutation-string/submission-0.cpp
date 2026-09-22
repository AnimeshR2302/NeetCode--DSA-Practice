class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int start = 0, len = s1.length();
        vector<int> cnt1(26, 0), cnt2(26, 0);

        for(char& x: s1) cnt1[x - 'a']++;
        
        for(int end = 0; end < s2.length();end++) {
            cnt2[s2[end] - 'a']++;

            while((end - start + 1) > len) {
                cnt2[s2[start] - 'a']--;
                start++;
            }

            if(cnt1 == cnt2) return true;
        }

        return false;
    }
};