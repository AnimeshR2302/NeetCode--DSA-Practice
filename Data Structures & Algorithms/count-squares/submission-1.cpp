class CountSquares {
    unordered_map<int, unordered_map<int,int>> freq;

    int get(int x, int y) {
        auto it = freq.find(x);
        if(it == freq.end()) return 0;

        auto jt = it->second.find(y);
        return jt == it->second.end() ? 0 : jt->second;
    }

public:
    CountSquares() {}

    void add(vector<int> point) {
        freq[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;

        auto it = freq.find(x);
        if(it == freq.end()) return 0;

        for(auto &[y2, cnt] : it->second) {
            int side = abs(y2 - y);
            if(side == 0) continue;

            ans += cnt * get(x + side, y) * get(x + side, y2);
            ans += cnt * get(x - side, y) * get(x - side, y2);
        }

        return ans;
    }
};