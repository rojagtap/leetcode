/*
feed is deque
map of follwer vs set of all users follwer follows
*/
class Twitter {
public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        feed.push_front(make_pair(userId, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        int feedcount = 10;
        vector<int> newsfeed;
        for (int i = 0; i < feed.size(); ++i) {
            if (feedcount == 0) break;

            if (feed[i].first == userId || (following.find(userId) != following.end() && following.at(userId).find(feed[i].first) != following.at(userId).end())) {
                newsfeed.push_back(feed[i].second);
                --feedcount;
            }
        }

        return newsfeed;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

private:
    deque<pair<int, int>> feed;
    unordered_map<int, unordered_set<int>> following;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */