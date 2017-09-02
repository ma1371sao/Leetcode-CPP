class Solution {
public:
	int findComplement(int num) {
		vector<int> bits;
		while (num) {
			if (num % 2 == 0) {
				bits.push_back(0);
			}
			else {
				bits.push_back(1);
			}
			num = num >> 1;
		}
		int complement = 0;
		for (int i = 0; i < bits.size(); i++) {
			if (!bits[i]) {
				complement += pow(2, i);
			}
		}
		return complement;
	}
};