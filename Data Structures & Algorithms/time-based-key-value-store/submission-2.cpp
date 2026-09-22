class TimeMap {
private:
    unordered_map<int, string> timeval;
    unordered_map<string, vector<int>> keytimes;

public:
    void set(string key, string value, int timestamp) {
        timeval[timestamp] = value;

        auto itr = keytimes.find(key);
        if(itr == keytimes.end()) keytimes[key] = {};
        
        keytimes[key].emplace_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(keytimes.find(key) == keytimes.end()) return "";

        vector<int>& v = keytimes[key];
        auto timep = upper_bound(v.begin(), v.end(), timestamp);

        if(timep == v.begin()) return "";
        else timep--;

        return timeval[*timep];
    }
};