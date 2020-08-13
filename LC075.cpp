class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = nums.size() - 1;
        for (int i = 0; i <= two && i >= zero; i++) {
            while (i <= two && i >= zero) {
                if (nums[i] == 0) {
                    nums[i] = nums[zero];
                    nums[zero] = 0;
                    zero++;
                } else if (nums[i] == 2) {
                    nums[i] = nums[two];
                    nums[two] = 2;
                    two--;
                } else
                    break;
            }
        }
    }
};
