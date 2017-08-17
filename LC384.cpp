class Solution {
public:
	vector<int> original;
	vector<int> shuffleNums;
	Solution(vector<int> nums) {
		original = nums;
		shuffleNums = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		shuffleNums = original;
		return original;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> shuffled;
		while (shuffleNums.size() != 0) {
			int selectedPos = rand() % shuffleNums.size();
			shuffled.push_back(shuffleNums[selectedPos]);
			shuffleNums[selectedPos] = shuffleNums.back();
			shuffleNums.pop_back();
		}
		shuffleNums = shuffled;
		return shuffleNums;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/