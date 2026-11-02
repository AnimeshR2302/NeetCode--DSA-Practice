class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        bool f0, f1,f2;
        f0 = f1 = f2 = false;

        for (const auto& t : triplets) {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;

            if (t[0] == target[0]) f0 = true;
            if (t[1] == target[1]) f1 = true;
            if (t[2] == target[2]) f2 = true;

            if (f0 && f1 && f2) return true;
        }

        return f0 && f1 && f2;
    }
};