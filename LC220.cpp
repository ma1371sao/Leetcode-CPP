class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <= 1 || t < 0 || k <= 0)    return false;
        set<long long> set_nums;
        unordered_map<int,int> num_pos;
        long long tt = t;
        for(int i = 0; i < nums.size(); i++){
            if(i > k && num_pos[nums[i - k - 1]] == i - k - 1)
                set_nums.erase(nums[i - k - 1]);
            set<long long>::iterator it = set_nums.lower_bound(nums[i] - tt);
            if(it != set_nums.end() && (*it) <= nums[i] + tt)
                return true;
            set_nums.insert(nums[i]);
            num_pos[nums[i]] = i;
        }
        return false;
    }
};
