class LRUCache {
private:
    unordered_map<int,int> keyval, time_to_key, key_to_time;
    int min, max, time, cap;
public:
    LRUCache(int capacity) {
        time = 0;
        min = 1;
        cap = max = capacity;

        key_to_time.reserve(capacity);
        time_to_key.reserve(capacity);
    }
    
    int get(int key) {
        time++;
        auto itr = key_to_time.find(key);
        if(itr == key_to_time.end()) return -1;

        auto titr = time_to_key.find(itr->second);
        if(titr != time_to_key.end()) {
            time_to_key.erase(titr);
        }

        key_to_time[key] = time;
        time_to_key[time] = key;

        return keyval[key];
    }
    
    void put(int key, int value) {
        if(get(key) != -1) {
            keyval[key] = value;
            return;
        }

        if(cap <= 0) return;

        if(time_to_key.size() < cap) {
            time_to_key[time] = key;
            key_to_time[key] = time;
            keyval[key] = value;
        } else {
            while(time_to_key.find(min) == time_to_key.end()) min++;

            auto titr = time_to_key.find(min++);
            if(titr != time_to_key.end()) {
                int oldKey = titr->second;
                time_to_key.erase(titr);
                key_to_time.erase(oldKey);
                keyval.erase(oldKey);
            }

            time_to_key[time] = key;
            key_to_time[key] = time;
            keyval[key] = value;
        }
    }
};