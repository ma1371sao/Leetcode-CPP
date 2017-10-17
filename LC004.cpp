class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total % 2)
			return findKth(nums1, 0, nums2, 0, (total + 1) / 2);
		else {
			double n1 = findKth(nums1, 0, nums2, 0, total / 2);
			double n2 = findKth(nums1, 0, nums2, 0, total / 2 + 1);
			return (n1 + n2) / 2;
		}
	}
	double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
		if (nums1.size() - start1 > nums2.size() - start2) return findKth(nums2, start2, nums1, start1, k);
		if (start1 == nums1.size()) return nums2[start2 + k - 1];
		if (start2 == nums2.size()) return nums2[start1 + k - 1];
		if (k == 1) return min(nums1[start1], nums2[start2]);
		int k1 = min(k / 2, (int)(nums1.size() - start1));
		int k2 = k - k1;
		if (nums1[start1 + k1 - 1] < nums2[start2 + k2 - 1]) return findKth(nums1, start1 + k1, nums2, start2, k - k1);
		else if (nums2[start2 + k2 - 1] < nums1[start1 + k1 - 1]) return findKth(nums1, start1, nums2, start2 + k2, k - k2);
		else return nums1[start1 + k1 - 1];
	}
};