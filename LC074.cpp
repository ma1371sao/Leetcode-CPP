class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if (row == 0)
			return false;
		int col = matrix[0].size();
		int left = 0;
		int right = row*col - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (matrix[mid / col][mid%col] == target)
				return true;
			if (matrix[mid / col][mid%col]<target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return false;
	}
};