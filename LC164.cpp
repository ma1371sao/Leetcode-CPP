/*
 Suppose there are N elements and they range from A to B.
 
 Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
 
 Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
 
 for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
 
 Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.
 
 For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
 */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxDiff = 0;
        int minNum = INT_MAX;
        int maxNum = INT_MIN;
        for (int num : nums) {
            minNum = min(minNum, num);
            maxNum = max(maxNum, num);
        }
        if (minNum == maxNum) return 0;
        int bucket_width = ceil((maxNum - minNum) * 1.0 / nums.size());
        int bucket_size = (maxNum - minNum) / bucket_width + 1;
        vector<int> bucket_max(bucket_size, INT_MIN);
        vector<int> bucket_min(bucket_size, INT_MAX);
        for (int num : nums) {
            int idx = (num - minNum) / bucket_width;
            bucket_max[idx] = max(bucket_max[idx], num);
            bucket_min[idx] = min(bucket_min[idx], num);
        }
        int pre = minNum;
        for (int i = 0; i < bucket_size; i++) {
            if (bucket_min[i] == INT_MAX) continue;
            maxDiff = max(maxDiff, bucket_min[i] - pre);
            pre = bucket_max[i];
        }
        return maxDiff;
    }
};
