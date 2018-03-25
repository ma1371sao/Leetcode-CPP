//method1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        buy[1] = max(buy[0], -prices[1]);
        sell[1] = max(sell[0], prices[1] + buy[0]);
        for (int i = 2; i < prices.size(); i++) {
            buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[prices.size() - 1];
    }
};

//method2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<int> maxPf(prices.size(), 0);
        int pfBefore = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxPf[i] = max(prices[i] + pfBefore, maxPf[i - 1]);
            if (i - 2 >= 0)
                pfBefore = max(maxPf[i - 2] - prices[i], pfBefore);
            else
                pfBefore = max(-prices[i], pfBefore);
        }
        return maxPf[prices.size() - 1];
    }
};
