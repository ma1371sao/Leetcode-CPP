class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int idx_min;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
                l = mid + 1;
            else 
                r = mid;
        }
        idx_min = l;
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[(mid + idx_min) % nums.size()] > target)
                r = mid - 1;
            else if (nums[(mid + idx_min) % nums.size()] < target)
                l = mid + 1;
            else
                return (mid + idx_min) % nums.size();
        }
        return -1;
    }
};