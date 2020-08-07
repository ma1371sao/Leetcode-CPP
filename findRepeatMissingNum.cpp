//https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/

vector<int> findRepeatMissingNum(vector<int>& nums) {
    vector<int> ans(2);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[abs(nums[i]) - 1] < 0)
            ans[0] = abs(nums[i]);
        else
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            ans[1] = i + 1;
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> nums{3,1,3};
    vector<int> arr = findRepeatMissingNum(nums);
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    return 0;
}
