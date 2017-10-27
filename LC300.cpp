//1. O(n^2)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (!n)  return 0;
		vector<int> dp(n, 0);
		dp[0] = 1;
		for (int i = 1; i<n; i++) {
			int max = 1;
			for (int j = i - 1; j >= 0; j--)
				if (nums[j]<nums[i] && dp[j] + 1>max)
					max = dp[j] + 1;
			dp[i] = max;
		}
		int res = 1;
		for (int i = 0; i<n; i++)
			if (dp[i]>res)
				res = dp[i];
		return res;
	}
};

//2. O(nlogn)

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		vector<int> minNumWithLen(nums.size(), 0);
		minNumWithLen[0] = nums[0];
		int curLen = 1;
		for (int i = 1; i < nums.size(); i++) {
			int j = Bsearch(minNumWithLen, 0, curLen - 1, nums[i]);
			if (j != -1)
				minNumWithLen[j] = nums[i];
			if (j == curLen)
				curLen++;
		}
		return curLen;
	}
	int Bsearch(vector<int>& minNumWithLen, int low, int high, int key) {
		while (low <= high) {
			if (minNumWithLen[high] < key) return high + 1;
			if (minNumWithLen[low] > key) return low;
			int mid = low + (high - low) / 2;
			if (minNumWithLen[mid] > key)
				high = mid - 1;
			else if (minNumWithLen[mid] < key)
				low = mid + 1;
			else
				return -1;
		}
		return -1;
	}
};