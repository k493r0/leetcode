#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>
#include <functional>
#include <hash_set>

/*
 * https://leetcode.com/problems/contains-duplicate/
 * 217. Contains Duplicate
 * Level: Easy
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 */
class Solution{
public:
    /**
     * Optimal Solution using unordered_set (HashMap)
     * Time Complexity: O(N log N), Memory Complexity: O(1)
     * @param nums
     * @return true if any value appears at least twice in the array, false if all values are distinct
     */
    bool containsDuplicate(std::vector<int>& nums){
        std::unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++){
            if(set.find(nums[i]) != set.end()){
                return true;
            }
            set.insert(nums[i]);
        }
        return false;
    }

    /**
     * Also optimal solution by sorting the array
     * Time Complexity: O(N log N), Memory Complexity: O(1)
     * @param nums
     * @return true if any value appears at least twice in the array, false if all values are distinct
     */
    bool containsDuplicate2(std::vector<int>& nums){

        sort(nums.begin(), nums.end());

        for(int idx = 0; idx < nums.size() - 1; idx++) {
            if(nums[idx] == nums[idx + 1])
                return true;
        }
        return false;
    }

    /**
     * Naive Solution
     * Time Complexity: O(N^2), Memory Complexity: O(1)
     * @param nums
     * @return true if any value appears at least twice in the array, false if all values are distinct
     */
    bool containsDuplicate3(std::vector<int> & nums){
        for(int i = 0; i < nums.size() ; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};


int main() {
    Solution s;

    // Example 1: Input: [1,2,3,1] Output: true
    std::vector<int> v1 = {1,2,3,1};
    // Example 2: Input: [1,2,3,4] Output: false
    std::vector<int> v2 = {1,2,3,4};
    // Example 3: Input: [1,2,3,4,5,6,7] Output: True
    std::vector<int> v3 = {1,1,1,3,3,4,3,2,4,2};

    // Store vectors in a vector of vectors
    std::vector<std::vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // Create vector with pointers to each function in the class
    std::vector<std::function<bool(std::vector<int>&)>> f;
    f.push_back(std::bind(&Solution::containsDuplicate, s, std::placeholders::_1));
    f.push_back(std::bind(&Solution::containsDuplicate2, s, std::placeholders::_1));
    f.push_back(std::bind(&Solution::containsDuplicate3, s, std::placeholders::_1));

    // Run the functions on the vectors
    for (auto& func : f) {
        std::cout << "Function: " << func.target_type().name() << std::endl;
        for (auto& vec : v) {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            bool result = func(vec);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Result: " << result << " Time: " << std::chrono::duration<double, std::milli>(end - begin).count() << "ms" << std::endl;
        }
    }

    return 0;
}
