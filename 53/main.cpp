#include <iostream>
#include <vector>
#include <climits>
#include <initializer_list>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max = INT_MIN, sum = 0;
        for (int num : nums) {
            sum += num;
            max = std::max(max, sum); // max = max > sum ? max : sum;
            if (sum < 0) { // if sum < 0, then the sum of the next element is smaller than the next element itself
                sum = 0;
            }
        }
        return max;
    }
};

class Solution2 {
public:
    int maxSubArray(std::vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(std::vector<int>& array, int left, int right){
        if (left > right) return INT_MIN; // if left > right, then the max subarray is empty

        int mid = left + (right - left) / 2;
        int leftMax = 0, rightMax = 0;

        for (int i = mid - 1, sum = 0; i >= left; --i) { // find the max subarray in the left half
            sum += array[i];
            leftMax = std::max(leftMax, sum);
        }

        for (int i = mid + 1, sum = 0; i <= right; ++i) { // find the max subarray in the right half
            sum += array[i];
            rightMax = std::max(rightMax, sum);
        }

        // return the max of the three
        return std::max(std::max(maxSubArray(array, left, mid - 1), maxSubArray(array, mid + 1, right)), leftMax + rightMax + array[mid]);
    }
};

int main() {

    Solution2 s;

    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << s.maxSubArray(nums) << std::endl;

    return 0;
}
