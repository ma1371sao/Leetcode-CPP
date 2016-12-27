class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row == 0)
			return;
		int col = matrix[0].size();
		int visr[10000];
		int visc[10000];
		memset(visr, 0, sizeof(visr));
		memset(visc, 0, sizeof(visc));
		for (int r = 0; r<row; r++)
		{
			for (int c = 0; c<col; c++)
			{
				if (matrix[r][c] == 0)
				{
					visr[r] = 1;
					visc[c] = 1;
				}
			}
		}
		for (int r = 0; r<row; r++)
			if (visr[r])
				for (int c = 0; c<col; c++)
					matrix[r][c] = 0;
		for (int c = 0; c<col; c++)
			if (visc[c])
				for (int r = 0; r<row; r++)
					matrix[r][c] = 0;
	}
};