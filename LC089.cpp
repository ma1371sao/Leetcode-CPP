class Solution {
public:
	vector<int> ans;
	vector<int> grayCode(int n) {
		if (n <= 0) {
			ans.push_back(0);
			return ans;
		}
		vector<int> bits(n, 0);
		DFS(bits, 0, n);
		return ans;
	}
	void DFS(vector<int>& bits, int pos, int n) {
		if (pos == n) {
			int num = 0;
			for (int i = pos - 1; i >= 0; i--)
				num = num + bits[i] * pow(2, pos - 1 - i);
			ans.push_back(num);
			return;
		}
		DFS(bits, pos + 1, n);
		if (bits[pos])
			bits[pos] = 0;
		else
			bits[pos] = 1;
		DFS(bits, pos + 1, n);
	}
};