class NumArray {
public:
	vector<int> v;
	int l;
	NumArray(vector<int> &nums) {
		l = nums.size();
		if (l == 0)
			return;
		v.push_back(nums[0]);
		for (int i = 1; i<l; i++)
		{
			v.push_back(v[i - 1] + nums[i]);
		}
	}

	int sumRange(int i, int j) {
		int ans = 0;
		if (l == 0)    return 0;
		if (i != 0)
			ans = v[j] - v[i - 1];
		else
			ans = v[j];
		return ans;
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);