class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> kv_map;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        kv_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!kv_map.count(key))
            return "";

        auto &timeline = kv_map[key];
        int l = 0, r = timeline.size();
        
        while(l < r) {
            int mid = l + (r-l) / 2;
            if (timeline[mid].first > timestamp) {
                r = mid;
            } else if (timeline[mid].first < timestamp) {
                l = mid + 1;
            } else {
                return timeline[mid].second;
            }
        }
        return l == 0? "" : timeline[l-1].second;
    }
};
