class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		map<int, int> m;
		int l = nums.size();
		int a, b;
		for (int i = 0; i<l; i++)
		{
			int temp = target - nums[i];
			if (m.find(temp) == m.end())
			{
				m.insert(pair<int, int>(nums[i], i));
			}
			else
			{
				res.push_back(m.find(temp)->second);
				res.push_back(i);
				return res;
			}
		}
		return res;
	}
};
