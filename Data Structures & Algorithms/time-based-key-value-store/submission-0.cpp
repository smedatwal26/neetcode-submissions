class TimeMap {
public:
    map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
             vector<pair<int,string>> vec = store[key];
             string ans = "";
             int low = 0,high = vec.size() - 1;
             while(low<=high){
                int mid = low + (high - low)/2;
                if(vec[mid].first <= timestamp){
                    ans = vec[mid].second;
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
             }
             return ans;
    }
};
