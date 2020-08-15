class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == 0) l++;
            else if (mid == A.size() - 1) r--;
            else {
                if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                    return mid;
                else if (A[mid] > A[mid - 1] && A[mid + 1] > A[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};

//If there are dup such as [0,1,1,1,2,1,1,0,0,0,0]
class Solution1 {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mid == 0) l++;
            else if (mid == A.size() - 1) r--;
            else {
                if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
                    return mid;
                else if (A[mid] > A[mid - 1] || A[mid + 1] > A[mid])
                    l = mid + 1;
                else if (A[mid] < A[mid + 1] || A[mid - 1] < A[mid])
                    r = mid - 1;
                else
                    r--;
            }
        }
        return -1;
    }
};
