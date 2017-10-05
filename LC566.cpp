class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int oriR = nums.size();
		if (oriR == 0) return nums;
		int oriC = nums[0].size();
		if (oriR * oriC != r * c) return nums;
		vector<vector<int>> reshaped(r, vector<int>(c, 0));
		int posr = 0;
		int posc = 0;
		for (int i = 0; i < oriR; i++) {
			for (int j = 0; j < oriC; j++) {
				reshaped[posr][posc] = nums[i][j];
				posc++;
				if (posc >= c) {
					posc = 0;
					posr++;
				}
			}
		}
		return reshaped;
	}
};