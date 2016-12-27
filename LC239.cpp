class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ans;
		int n = nums.size();
		if (n == 0 || k>n)
			return ans;
		priority_queue<int> pq;
		map<int, int> m;
		for (int i = 0; i<k - 1; i++)
		{
			pq.push(nums[i]);
			m[nums[i]] = i;
		}
		for (int i = k - 1; i<n; i++)
		{
			while (!pq.empty() && m[pq.top()]<i - k + 1)
				pq.pop();
			if (!pq.empty() && nums[i] >= pq.top())
				while (!pq.empty())
					pq.pop();
			pq.push(nums[i]);
			m[nums[i]] = i;
			ans.push_back(pq.top());
		}
		return ans;
	}
};