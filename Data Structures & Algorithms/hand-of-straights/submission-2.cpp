class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for (int& x : hand) mp[x]++;
        
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int num = it->first;
            int cnt = it->second;
            if (cnt <= 0) continue;

            for (int i = 0; i < groupSize; i++)
                if (mp[num + i] >= cnt) mp[num + i] -= cnt;
                else return false; 
        }
        
        return true;
    }
};