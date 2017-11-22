class RandomizedCollection {
public:
	/** Initialize your data structure here. */
	vector<pair<int, int>> nums;
	unordered_map<int, vector<int>> num_pos;
	RandomizedCollection() {

	}

	/** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
	bool insert(int val) {
		bool hasExisted = false;
		if (num_pos.find(val) != num_pos.end()) hasExisted = true;
		num_pos[val].push_back(nums.size());
		nums.push_back(make_pair(val, num_pos[val].size() - 1));
		return !hasExisted;
	}

	/** Removes a value from the collection. Returns true if the collection contained the specified element. */
	bool remove(int val) {
		if (num_pos.find(val) == num_pos.end()) return false;
		int pos = num_pos[val].back();
		nums[pos].first = nums.back().first;
		nums[pos].second = nums.back().second;
		num_pos[nums[pos].first][nums[pos].second] = pos;
		num_pos[val].pop_back();
		if (num_pos[val].empty()) num_pos.erase(val);
		nums.pop_back();
		return true;
	}

	/** Get a random element from the collection. */
	int getRandom() {
		return nums[rand() % nums.size()].first;
	}
};

/**
* Your RandomizedCollection object will be instantiated and called as such:
* RandomizedCollection obj = new RandomizedCollection();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/