#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2; // avoid overflow
            if (nums[mid] == target) return mid; // found
            else if (nums[mid] < target) low = mid + 1; // search right
            else high = mid - 1; // search left
        }
        return -1; // not found
    }
};

int main() {
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution s;
    std::cout << s.search(nums, target) << std::endl;
    return 0;
}
