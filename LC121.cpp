class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = 1;
		if (prices.size() == NULL)
			return 0;
		vector<int>p;
		p.push_back(0);
		int min_i = prices[0];
		for (int i = 1; i<prices.size(); i++)
		{
			if (prices[i]<prices[i - 1])
				p.push_back(p[i - 1]);
			else {
				if (prices[i] - min_i>p[i - 1])
					p.push_back(prices[i] - min_i);
				else
					p.push_back(p[i - 1]);
			}
			if (prices[i]<min_i)
				min_i = prices[i];
		}
		return *(p.end() - 1);
	}
};