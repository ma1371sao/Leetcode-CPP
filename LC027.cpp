class Solution1 {
public:
	int removeElement(vector<int>& nums, int val) {
		return remove(nums.begin(), nums.end(), val) - nums.begin();
	}
};


class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		int i, j;
		for (i = 0, j = 0; j<nums.size();)
		{
			if (nums[j] == val)
				j++;
			else if (j>i)
			{
				nums[i] = nums[j];
				j++;
				i++;
			}
			else
			{
				j++;
				i++;
			}
		}
		return i;
	}
};