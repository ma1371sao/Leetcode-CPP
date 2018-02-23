class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> rob1(nums.size() + 1, 0);
        vector<int> rob2(nums.size() + 1, 0);
        rob1[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            rob1[i + 1] = max(rob1[i], nums[i] + rob1[i - 1]);
            rob2[i + 1] = max(rob2[i], nums[i] + rob2[i - 1]);
        }
        return max(rob1[nums.size() - 1], rob2[nums.size()]);
    }
};
