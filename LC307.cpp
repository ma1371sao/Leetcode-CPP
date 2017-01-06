class NumArray {
public:
	NumArray(vector<int> &nums) {
		num = nums;
		lowbit.resize(num.size() + 1, 0);
		for (int i = 0; i<num.size(); i++)
			add(num[i], i + 1);
	}

	void add(int val, int index) {
		while (index <= num.size()) {
			lowbit[index] += val;
			index += index&-index;
		}
	}

	void update(int i, int val) {
		int index = i + 1;
		while (index <= num.size()) {
			lowbit[index] += val - num[i];
			index += index&-index;
		}
		num[i] = val;
	}

	int sum(int index) {
		int res = 0;
		while (index>0) {
			res += lowbit[index];
			index -= index&-index;
		}
		return res;
	}

	int sumRange(int i, int j) {
		return sum(j + 1) - sum(i);
	}
private:
	vector<int> num;
	vector<int> lowbit;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);