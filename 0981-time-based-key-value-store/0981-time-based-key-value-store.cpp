/*
use binary search for closest timestamp
*/
class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (timemap.find(key) == timemap.end()) {
            timemap[key] = vector<pair<int, string>>();
        }
        timemap.at(key).push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (timemap.find(key) != timemap.end()) {
            int l = 0, r = timemap.at(key).size() - 1;
            
            int closest = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                
                if (timemap.at(key)[mid].first < timestamp) {
                    closest = mid;
                    l = mid + 1;
                } else if (timemap.at(key)[mid].first > timestamp) {
                    r = mid - 1;
                } else {
                    return timemap.at(key)[mid].second;
                }
            }
            
            return closest == -1 ? "" : timemap.at(key)[closest].second;
        } else {
            return "";
        }
    }

private:
    unordered_map<string, vector<pair<int, string>>> timemap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */