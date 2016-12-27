class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		map<int, int> m;
		int l1 = nums1.size();
		int l2 = nums2.size();
		if (l1 == 0 || l2 == 0)
			return ans;
		for (int i = 0; i<l1; i++)
			if (m.find(nums1[i]) == m.end())
				m[nums1[i]] = 1;
		for (int i = 0; i<l2; i++)
		{
			if (m.find(nums2[i]) != m.end() && m[nums2[i]]>0)
			{
				ans.push_back(nums2[i]);
				m[nums2[i]]--;
			}
		}
		return ans;
	}
};

// two pointer

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		int n1 = nums1.size();
		int n2 = nums2.size();
		if (n1 == 0 || n2 == 0)  return res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0;
		int j = 0;
		while (i<n1 && j<n2) {
			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				for (i = i + 1; i<n1 && nums1[i - 1] == nums1[i]; i++);
				for (j = j + 1; j<n2 && nums2[j - 1] == nums2[j]; j++);
			}
			else if (nums1[i]>nums2[j]) {
				for (j = j + 1; j<n2 && nums2[j - 1] == nums2[j]; j++);
			}
			else {
				for (i = i + 1; i<n1 && nums1[i - 1] == nums1[i]; i++);
			}
		}
		return res;
	}
};