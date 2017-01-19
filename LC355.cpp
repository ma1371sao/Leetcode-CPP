class Twitter {
public:
	/** Initialize your data structure here. */
	unordered_map<int, int> hashtweet;
	vector<int> tweet;
	unordered_map<int, unordered_set<int>>follower;
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		hashtweet[tweetId] = userId;
		tweet.push_back(tweetId);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> res;
		int count = 0;
		for (int i = tweet.size() - 1; i >= 0 && count<10; i--) {
			if (follower[userId].find(hashtweet[tweet[i]]) != follower[userId].end() || hashtweet[tweet[i]] == userId) {
				res.push_back(tweet[i]);
				count++;
			}
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		follower[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		follower[followerId].erase(followeeId);
	}
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/