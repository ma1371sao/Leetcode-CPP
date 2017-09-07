class Solution {
public:
	vector<int> constructRectangle(int area) {
		vector<int> wAndL(2, 0);
		int w, l;
		for (l = area; l >= sqrt(area); l--) {
			if (area % l == 0) {
				w = area / l;
				wAndL[0] = l;
				wAndL[1] = w;
			}
		}
		return wAndL;
	}
};