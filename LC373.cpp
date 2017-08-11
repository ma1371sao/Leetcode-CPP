struct cmp {
	bool operator() (const pair<int, int>& num1, const pair<int, int>& num2) {
		return num1.first + num1.second > num2.first + num2.second;
	}
};
class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> smallestPairs;
		if (k == 0)
			return smallestPairs;
		int num1 = 0;
		int num2 = 0;
		priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> ascPairs;
		for (int num1 = 0; num1 < nums1.size(); num1++) {
			for (int num2 = 0; num2 < nums2.size(); num2++) {
				ascPairs.push(make_pair(nums1[num1], nums2[num2]));
			}
		}
		for (int num = 0; num < k && !ascPairs.empty(); num++) {
			smallestPairs.push_back(ascPairs.top());
			ascPairs.pop();
		}
		return smallestPairs;
	}
};