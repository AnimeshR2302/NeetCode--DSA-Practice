class Twitter {
private:
    struct User {
        int oldest = 0, count = 0;
        array<pair<int,int>, 10> tweets;
        vector<User*> followers;
    };

    vector<User*> ulist;
    int ttime;

public:
    Twitter() {
        ulist.resize(500, nullptr);
        ttime = 0;
    }

    ~Twitter() {
        for (User* u : ulist) delete u;
    }

    Twitter(const Twitter&) = delete;
    Twitter& operator=(const Twitter&) = delete;

    void postTweet(int userId, int tweetId) {
        if(!ulist[userId - 1]) ulist[userId - 1] = new User();

        User*& cur = ulist[userId - 1];

        cur->tweets[cur->oldest] = {tweetId, ttime++};
        cur->oldest = (cur->oldest + 1) % 10;
        cur->count = min(10, cur->count + 1);
    }

    vector<int> getNewsFeed(int userId) {
        vector<span<const pair<int,int>>> feed;
        vector<int> ans, pos, left;

        if(!ulist[userId - 1]) return ans;

        User*& cur = ulist[userId - 1];

        if(cur->count) {
            feed.emplace_back(cur->tweets);
            pos.emplace_back((cur->oldest + 9) % 10);
            left.emplace_back(cur->count);
        }

        for(User*& u: cur->followers) {
            if(!u->count) continue;

            feed.emplace_back(u->tweets);
            pos.emplace_back((u->oldest + 9) % 10);
            left.emplace_back(u->count);
        }

        while(ans.size() != 10) {
            int latest = -1;
            int arrIdx = -1;

            for(int i = 0; i < feed.size(); i++) {
                if(left[i] == 0) continue;

                const auto& arr = feed[i];
                int cpos = pos[i];

                if(arr[cpos].second > latest) {
                    latest = arr[cpos].second;
                    arrIdx = i;
                }
            }

            if(arrIdx == -1) break;

            ans.emplace_back(feed[arrIdx][pos[arrIdx]].first);

            pos[arrIdx] = (pos[arrIdx] + 9) % 10;
            left[arrIdx]--;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;

        if(!ulist[followerId - 1]) ulist[followerId - 1] = new User();
        if(!ulist[followeeId - 1]) ulist[followeeId - 1] = new User();

        vector<User*>& vec = ulist[followerId - 1]->followers;

        if(find(vec.begin(), vec.end(), ulist[followeeId - 1]) == vec.end())
            vec.emplace_back(ulist[followeeId - 1]);
    }

    void unfollow(int followerId, int followeeId) {
        if(!ulist[followerId - 1] || !ulist[followeeId - 1]) return;

        vector<User*>& vec = ulist[followerId - 1]->followers;
        auto itr = find(vec.begin(), vec.end(), ulist[followeeId - 1]);

        if(itr == vec.end()) return;
        vec.erase(itr);
    }
};