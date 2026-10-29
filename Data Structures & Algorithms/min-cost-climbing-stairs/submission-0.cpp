class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int pm2 = cost[0], pm1 = cost[1];

        for(int i=2;i<cost.size();i++){
            pm2 ^= pm1;
            pm1 ^= pm2;
            pm2 ^= pm1;
            pm1 = min(pm2,pm1) + cost[i];
        }

        return min(pm2,pm1);
    }
};
