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
		int n = nums.size();
		if (n == 0)
			return 0;
		vector<int> lenlast(n, 0);
		lenlast[0] = nums[0];
		int curlen = 1;
		for (int i = 1; i<n; i++) {
			int larger = Bsearch(lenlast, 0, curlen - 1, nums[i]);
			if (larger != -1)
				lenlast[larger] = nums[i];
			if (larger == curlen)
				curlen++;
		}
		return curlen;
	}
	int Bsearch(vector<int> lenlast, int low, int high, int key) {
		while (low <= high) {
			if (lenlast[high]<key) return high + 1;
			if (lenlast[low]>key) return low;
			int mid = low + (high - low) / 2;
			if (lenlast[mid]<key)
				low = mid + 1;
			else if (lenlast[mid]>key)
				high = mid - 1;
			else
				return -1;
		}
		return -1;
	}
};