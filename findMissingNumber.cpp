//https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/
int missingNumberHelper(int n1, int n2, int n3) {
    if (n2 - n1 > n3 - n2)
        return n1 + (n3 - n2);
    else if (n2 - n1 < n3 - n2)
        return n2 + (n2 - n1);
    else return -1;
}

int missingNumber(vector<int> nums) {
    int n = nums.size();
    if (n < 3) return -1;
    int l = 0;
    int r = n - 1;
    int dis = -1;
    
    int num = missingNumberHelper(nums[0], nums[1], nums[2]);
    if (num > 0) return num;
    dis = nums[1] - nums[0];
    
    num = missingNumberHelper(nums[n - 3], nums[n - 2], nums[n - 1]);
    if (num > 0) return num;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid > 0 && mid < n - 1) {
            int num = missingNumberHelper(nums[mid - 1], nums[mid], nums[mid + 1]);
            if (num > 0) return num;
        }
        
        if (nums[mid] - nums[l] == (mid - l) * dis) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums{1, 6, 11, 16, 21, 31};
    cout << missingNumber(nums) << endl;
}
