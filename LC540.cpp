class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == 0) {
                if (nums[mid] != nums[mid + 1]) return nums[mid];
                l = mid + 2;
            } else if (mid == n - 1) {
                if (nums[mid] != nums[mid - 1]) return nums[mid];
                r = mid - 2;
            } else {
                if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
                    return nums[mid];
                if (nums[mid] == nums[mid + 1]) {
                    if ((mid - l + 1) % 2)
                        l = mid + 2;
                    else
                        r = mid - 1;
                } else {
                    if ((r - mid + 1) % 2)
                        r = mid - 2;
                    else
                        l = mid + 1;
                }
            }
        }
        return 0;
    }
};
