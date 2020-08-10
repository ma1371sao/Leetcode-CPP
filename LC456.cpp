class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        
        set<int, greater<int>> nSet;
        vector<int> leftMin(nums.size());
        int minNum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            leftMin[i] = minNum;
            minNum = min(nums[i], minNum);
        }
        
        nSet.insert(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i > 0; i--) {
            if (nSet.upper_bound(nums[i]) != nSet.end())
                if (*(nSet.upper_bound(nums[i])) > leftMin[i])
                    return true;
            nSet.insert(nums[i]);
        }
        return false;
    }
};
