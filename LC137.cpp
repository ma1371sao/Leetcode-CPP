class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i<32; i++) {
			int count = 0;
			int bit = 1 << i;
			for (int j = 0; j<n; j++) {
				if (bit&nums[j])
					count++;
			}
			if (count % 3)
				ans += bit;
		}
		return ans;
	}
};