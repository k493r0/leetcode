#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        // Moore's Voting Algorithm
        int count = 0, candidate;
        for (int num: nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {

    std::vector<int> nums = {2,2,1,1,1,2,2};

    Solution s;
    std::cout << s.majorityElement(nums) << std::endl;

    return 0;
}
