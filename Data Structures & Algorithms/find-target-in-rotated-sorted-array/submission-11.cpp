class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int high = -1001;
        int highPos;

        if (target == nums[0]) {
            return 0;
        }

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > high) {
                high = nums[mid];
                highPos = mid;
            }

            if (nums[l] <= nums[mid]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        // std::cout << high << "\n";

        if (target == high) {
            return highPos;
        }

        if (target > nums[0]) {
            l = 0;
            r = highPos - 1;
        } else {
            l = highPos + 1;
            r = nums.size() - 1;
        }

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return (l < nums.size() && (nums[l] == target)) ? l : -1;
            
    }
};
