class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int ori = abs(nums[i]);
            if (nums[ori] < 0) return ori;
            nums[ori] = -nums[ori];
        }
        return 0;
    }
};
