class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> kindCandy;
		for (int i = 0; i < candies.size(); i++)
			if (kindCandy.find(candies[i]) == kindCandy.end())
				kindCandy.insert(candies[i]);
		if (kindCandy.size() <= candies.size() / 2)
			return kindCandy.size();
		return candies.size() / 2;
	}
};