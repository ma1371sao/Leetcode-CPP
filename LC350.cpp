class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> m;
		int l1 = nums1.size();
		int l2 = nums2.size();
		vector<int>ans;
		for (int i = 0; i<l1; i++)
		{
			if (m.find(nums1[i]) == m.end())
				m[nums1[i]] = 1;
			else
				m[nums1[i]]++;
		}
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