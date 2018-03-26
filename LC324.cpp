class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return;
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mid = *(nums.begin() + n / 2);
        int l = 0;
        int r = nums.size() - 1;
        int cur = 0;
        #define A(i) nums[(2 * i + 1) % (n | 1)]
        while (cur <= r) {
            if (A(cur) > mid)
                swap(A(l++), A(cur++));
            else if (A(cur) < mid)
                swap(A(r--), A(cur));
            else
                cur++;
        }
    }
};