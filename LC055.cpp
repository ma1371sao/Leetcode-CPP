class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = 0;
        for (int i = 0; i < nums.size() && i <= right; i++)
            right = max(right, nums[i] + i);
        if (right >= nums.size() - 1) return true;
        return false;
    }
};