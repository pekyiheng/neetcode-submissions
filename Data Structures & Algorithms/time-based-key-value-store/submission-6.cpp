class TimeMap {
public:
    std::unordered_map<string, vector<int>> m;
    std::unordered_map<string, std::unordered_map<int, string>> ms;
    int ts = 0;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ms[key][timestamp] = value;
        if (!m.contains(key)) {
            m[key].reserve(20000);
        }
        m[key].push_back(timestamp);
        ts = timestamp;
    }
    
    string get(string key, int timestamp) {

        if (!m.contains(key)) {
            return "";
        }

        int vLen = m[key].size();
        int mints = m[key][0];

        if (ms[key].contains(timestamp)) {
            return ms[key][timestamp];
        }

        if (timestamp >= ts) {
            int idx = m[key].back();
            return ms[key][idx];
        }   else if (timestamp < mints) {
            return "";
        }

        int l = 0;
        int r = vLen - 1;
        int retIdx = m[key][0];

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (m[key][mid] < timestamp) {
                retIdx = m[key][mid];
                l = mid+1;
            } else {
                r = mid;
            }
        }

        return ms[key][retIdx];
    }
};
