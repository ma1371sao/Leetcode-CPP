class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int r = nums.size() - 1;
        int l = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] > nums[r]) {
                if (nums[mid] > target && nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[mid] < nums[r]) {
                if (nums[mid] < target && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid;
            }
            else
                r--;
        }
        return false;
    }
};