class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxPdt = nums[0];
        int minPdt = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmpMax = max(nums[i], nums[i] * maxPdt);
            tmpMax = max(tmpMax, minPdt * nums[i]);
            minPdt = min(nums[i], nums[i] * minPdt);
            minPdt = min(minPdt, maxPdt * nums[i]);
            maxPdt = tmpMax;
            res = max(res, maxPdt);
        }
        return res;
    }
};
