// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int mid, l = 1, r = n;
		mid = l + (r - l) / 2;
		while (l<r)
		{
			bool re = isBadVersion(mid);
			bool tmp;
			if (re == true)
			{
				r = mid;
				mid = l + (r - l) / 2;
			}
			else
			{
				l = mid + 1;
				mid = l + (r - l) / 2;
			}
		}
		return mid;
	}
};