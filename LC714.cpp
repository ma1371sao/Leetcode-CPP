//method1
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		if (prices.size() < 2) return 0;
		vector<int> buy(prices.size(), 0);
		vector<int> sell(prices.size(), 0);
		buy[0] = -prices[0];
		buy[1] = max(-prices[1], buy[0]);
		sell[1] = max(0, prices[1] + buy[0] - fee);
		for (int i = 2; i < prices.size(); i++) {
			buy[i] = max(sell[i - 1] - prices[i], buy[i - 1]);
			sell[i] = max(buy[i - 1] + prices[i] - fee, sell[i - 1]);
		}
		return sell[prices.size() - 1];
	}
};

//method2
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if (prices.size() == 0) return 0;
        vector<int> maxPf(prices.size(), 0);
        int pfBefore = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxPf[i] = max(maxPf[i - 1], prices[i] + pfBefore - fee);
            pfBefore = max(pfBefore, maxPf[i - 1] - prices[i]);
        }
        return maxPf[prices.size() - 1];
    }
};
