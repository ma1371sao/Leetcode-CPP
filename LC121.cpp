class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int diff = 0;
		int minNum = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] >= minNum)
				diff = max(diff, prices[i] - minNum);
			else
				minNum = prices[i];
		}
		return diff;
	}
};