class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        if (nums.size() < 3) return nums.size();
        int slow = 0;
        for (; fast < nums.size(); fast++) {
            nums[slow++] = nums[fast];
            if (fast + 1 < nums.size() && nums[fast] == nums[fast + 1])
                nums[slow++] = nums[fast + 1];
            for (; fast + 1 < nums.size() && nums[fast] == nums[fast + 1]; fast++);
        }
        return slow;
    }
};