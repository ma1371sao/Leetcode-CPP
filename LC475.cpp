class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		vector<int> cover(heaters.size(), 0);
		int indexHeater = 0;
		for (int i = 0; i < houses.size(); i++) {
			for (; indexHeater < heaters.size() - 1 &&
				abs(heaters[indexHeater] - houses[i]) >= abs(heaters[indexHeater + 1] - houses[i]); indexHeater++);
			cover[indexHeater] = max(cover[indexHeater], abs(heaters[indexHeater] - houses[i]));
		}
		int minRadius = 0;
		for (int i = 0; i < cover.size(); i++) {
			minRadius = max(minRadius, cover[i]);
		}
		return minRadius;
	}
};