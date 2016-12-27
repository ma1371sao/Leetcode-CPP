class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int l = nums.size();
		int a, b;
		vector<int> ori = nums;
		vector<int> res;
		sort(nums.begin(), nums.begin() + l);
		for (int i = 0, j = l - 1; i<j;)
		{
			if (nums[i] + nums[j] == target)
			{
				if (nums[i] != nums[j])
				{
					a = find(ori.begin(), ori.end() + 1, nums[i]) - ori.begin();
					b = find(ori.begin(), ori.end() + 1, nums[j]) - ori.begin();
					if (a>b)
					{
						int temp = a;
						a = b;
						b = temp;
					}
					res.push_back(a);
					res.push_back(b);
					return res;
				}
				else
				{
					int flag = 0;
					for (int k = 0; k<l; k++)
					{
						if (ori[k] == nums[i])
							if (!flag)
							{
								a = k;
								flag = 1;
							}
							else
							{
								b = k;
								break;
							}
					}
					res.push_back(a);
					res.push_back(b);
					return res;
				}
			}
			else if (nums[i] + nums[j]>target)
				j--;
			else
				i++;
		}
		return res;
	}
};