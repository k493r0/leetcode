#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // The problem requires you to find the maximum value after the minimum value that provides the highest delta
        int max = 0;
        int min = INT_MAX;

        for(auto price:prices){
            if(price < min){ // Set the current price to minimum if it's the lowest so far
                min = price;
            } else if(price > min){ // If the current price is bigger than the minimum
                max = std::max(price - min, max); // Calculate the profit, and check if it's any higher than the existing delta
            }
        }
        return max;

    }
};

int main() {

    Solution solution;

    std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << solution.maxProfit(prices) << std::endl;

    std::vector<int> prices2 = {7,6,4,3,1};
    std::cout << solution.maxProfit(prices2) << std::endl;

    return 0;
}
