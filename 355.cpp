class Twitter {
public:
    class Node {
    public:
        set<int> follower;
        set<int> following;
    };

    /** Initialize your data structure here. */
    Twitter() {
        count = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (users.find(userId) == users.end()) {
            users.insert(pair<int, Node>(userId, Node()));
        }

        pair<int, int> curPair(userId, tweetId);
        contains.insert(pair<int, pair<int, int>>(count, curPair));
        count++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, Node>::iterator itr = users.find(userId);
        if (itr == users.end() || contains.empty()) return res;
        map<int, pair<int, int>>::iterator itrCon = contains.end();
        itrCon--;
        while (1) {
            if (itr->second.following.find(itrCon->second.first) == itr->second.following.end() && itrCon->second.first != userId) {
                if (itrCon == contains.begin()) break;
                itrCon--;
                continue;
            }
            res.push_back(itrCon->second.second);
            if (res.size() >= 10) return res;
            if (itrCon == contains.begin()) break;
            itrCon--;
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        map<int, Node>::iterator itr = users.find(followerId);
        if (itr == users.end()) {
            users.insert(pair<int, Node>(followerId, Node()));
            itr = users.find(followerId);
        }
        set<int>::iterator itrSet = itr->second.following.find(followeeId);
        if (itrSet == itr->second.following.end()) {
            itr->second.following.insert(followeeId);
        }

        itr = users.find(followeeId);
        if (itr == users.end()) {
            users.insert(pair<int, Node>(followeeId, Node()));
            itr = users.find(followeeId);
        }
        itrSet = itr->second.follower.find(followerId);
        if (itrSet == itr->second.follower.end()) {
            itr->second.follower.insert(followerId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        map<int, Node>::iterator itr = users.find(followerId);
        if (itr == users.end()) return;
        set<int>::iterator itrSet = itr->second.following.find(followeeId);
        if (itrSet != itr->second.following.end()) {
            itr->second.following.erase(itrSet);
        }

        itr = users.find(followeeId);
        if (itr == users.end()) return;
        itrSet = itr->second.follower.find(followerId);
        if (itrSet != itr->second.follower.end()) {
            itr->second.follower.erase(itrSet);
        }
    }

private:
    map<int, pair<int, int>> contains;
    map<int, Node> users;
    int count;  
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
