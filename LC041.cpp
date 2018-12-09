class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int fast = 0;
        int slow = 0;
        for (; fast < n; fast++) {
            if (nums[fast] > 0 && nums[fast] <= n)
                nums[slow++] = nums[fast];
        }
        for (int i = 0; i < slow; i++) {
            nums[nums[i] - 1] *= -1;
        }
        for (int i = 0; i < slow; i++)
            if (nums[i] > 0)
                return i + 1;
        return slow + 1;
    }
};
