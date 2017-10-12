class Solution {
public:
	int kEmptySlots(vector<int>& flowers, int k) {
		if (flowers.size() == 0) return -1;
		if (flowers.size() == 1 && k == 0) return 1;
		if (flowers.size() == 1) return -1;
		set<int> bloomPos;
		for (int i = 0; i < flowers.size(); i++) {
			int pos = flowers[i];
			auto it = bloomPos.insert(pos).first;
			if (it != bloomPos.begin()) {
				if (pos - *(--it) - 1 == k)
					return i + 1;
				it++;
			}
			if (++it != bloomPos.end()) {
				if (*it - pos - 1 == k)
					return i + 1;
			}
		}
		return -1;
	}
};