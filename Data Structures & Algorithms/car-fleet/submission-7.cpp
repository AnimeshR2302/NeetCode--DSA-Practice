class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>> vp;
        vp.reserve(position.size());

        for(int i = 0;i<position.size();i++) {
            int dist = target - position[i];
            float time = static_cast<float>(dist) / speed[i];
            
            vp.emplace_back(make_pair(dist, time));
        }
        
        sort(vp.begin(),vp.end());
        
        vector<float> v;
        while(!vp.empty()) {
            while(!v.empty() && v.back() <= vp.back().second) v.pop_back();
            v.emplace_back(vp.back().second);
            vp.pop_back();
        }

        return v.size();
    }
};