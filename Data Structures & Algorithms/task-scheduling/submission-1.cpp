class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        auto cmp = [](const pair<int,int> p1, const pair<int,int> p2) {
            if(p1.first == p2.first) return p1.second < p2.second;
            return p1.first > p2.first;
        };

        set<pair<int,int>, decltype(cmp)> remtasks;
        vector<int> lastup(26), freq(26);

        int remcnt = tasks.size(), task = 0;

        for(const char& x: tasks) freq[x-'A']++;
        for(int i=0;i<freq.size();i++) if(freq[i] != 0) remtasks.insert({freq[i],i});

        while(remcnt != 0) {
            task++;
            for(auto itr = remtasks.begin();itr!=remtasks.end();itr++) {
                int pos = itr->second;
                
                if(lastup[pos] == 0 || task - lastup[pos] > n) {
                    remcnt--;
                    lastup[pos] = task;

                    int cnt = itr->first - 1;
                    remtasks.erase(itr);

                    if(cnt!=0) remtasks.insert({cnt,pos});
                    break;
                }
            }
        }

        return task;
    }
};