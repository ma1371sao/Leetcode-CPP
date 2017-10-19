class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) return;
		if (m == 0) {
			nums1 = nums2;
			return;
		}
		int pos1 = m - 1;
		int pos2 = n - 1;
		for (int i = m + n - 1; i >= 0; i--) {
			if (pos1 >= 0 && pos2 >= 0) {
				if (nums1[pos1] > nums2[pos2]) {
					nums1[i] = nums1[pos1];
					pos1--;
				}
				else {
					nums1[i] = nums2[pos2];
					pos2--;
				}
			}
			else if (pos1 >= 0) {
				return;
			}
			else if (pos2 >= 0) {
				nums1[i] = nums2[pos2];
				pos2--;
			}
		}
	}
};