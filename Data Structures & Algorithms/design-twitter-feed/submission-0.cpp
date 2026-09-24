class Twitter {
public:
        int count;
        unordered_map<int,set<int>> followMap; // user,list of users follow list
        unordered_map<int,vector<vector<int>>> tweetMap; //userId,<count,tweetId>
    Twitter() {
       count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
      auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0]; // Max-Heap: latest timestamp first
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);
        followMap[userId].insert(userId);
        for(int followedId : followMap[userId]){
            if (tweetMap.count(followedId) > 0) {
            const vector<vector<int>> tweets = tweetMap[followedId];
            int index = tweets.size() - 1;
            //pushing timestamp,tweetID,
            maxHeap.push({tweets[index][0],tweets[index][1],followedId,index});
            }
        }
        while(!maxHeap.empty() && res.size() < 10){
            vector<int> cur = maxHeap.top();
            maxHeap.pop();
            res.push_back(cur[1]);
            int index = cur[3];
            if(index > 0){
                const vector<int> tweet = tweetMap[cur[2]][index - 1];
                maxHeap.push({tweet[0],tweet[1],cur[2],index - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
