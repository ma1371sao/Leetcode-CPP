int findKthMissingNum(vector<int>& nums, int k) {
    int numIdx = 1;
    int missNum = nums[0];
    int jth = 1;
    while (jth <= k) {
        missNum++;
        while (numIdx < nums.size() && missNum == nums[numIdx]) {
            missNum++;
            numIdx++;
        }
        jth++;
    }
    return missNum;
}
