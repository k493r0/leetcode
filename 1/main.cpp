#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i){
            // Check if current number is the number needed to meet the target value
            // e.g. if current = 7 and target = 9, we need 2 to meet target
            // Try to find 2 in map, if not found by the end of loop, no match exists
            if (map.find(target - nums[i]) == map.end()){ // Not found in map
                map[nums[i]] = i; // Store <number, index>
            }else{
                return {map[target - nums[i]], i}; // Else return the index of the required number and the current
            }
        }

        return {-1,-1}; // No need as constraint mentions only one valid answer exists
    }
};

int main() {

    Solution solution;

    std::vector<int> nums = {2,7,11,15};
    int target = 9;

    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << result[0] << " " << result[1] << std::endl;

    return 0;
}
