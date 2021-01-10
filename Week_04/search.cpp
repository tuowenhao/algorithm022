class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[0]){
                if (target < nums[mid] && target >= nums[0]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[n-1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
