class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int start = 0;
		int n = gas.size();
		if (n == 0)
			return -1;
		for (start = 0; start<n; start++) {
			int nowgas = 0;
			int flag = 1;
			for (int i = 0; i<n; i++) {
				nowgas += gas[(start + i) % n] - cost[(start + i) % n];
				if (nowgas<0) {
					flag = 0;
					start = start + i;
					break;
				}
			}
			if (flag)
				return start;
		}
		return -1;
	}
};