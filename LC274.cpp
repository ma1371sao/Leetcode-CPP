class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int h = citations.size();
		for (int ct : citations) {
			if (ct >= h)
				return h;
			h--;
		}
		return h;
	}
};