class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back() != 9) digits.back()++;
        else {
            int last = digits.size()-1;
            while(last>=0 && digits[last] != 9) last--;
            int first = last;
            while(first>0 && digits[first-1] == 9) first--;
            
            if(first==0) {
                fill(digits.begin(), digits.end(), 0);
                digits.emplace_back(0);
                digits.front()++;
            } else {
                for(int i=first;i<=last;i++) digits[i]=0;
                digits[first-1]++;
            }
        }

        return digits;
    }
};
