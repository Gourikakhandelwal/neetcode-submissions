class Twitter {
public:
map<int,unordered_set<int>> follows;
map<int,vector<pair<int,int>>> post;
int timeout;
    Twitter() {
        timeout=0;
    }

    void postTweet(int userId, int tweetId) {
        post[userId].push_back({timeout++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it:post[userId])pq.push(it);
        for(auto followee:follows[userId]){
            for(auto t:post[followee])pq.push(t);
        }
        int k=0;
        vector<int> res;
        while(!pq.empty() && k<10){
            res.push_back(pq.top().second);
            pq.pop();
            k++;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
