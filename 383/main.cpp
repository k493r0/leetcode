#include <iostream>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        // non unordered_map solution
        int count[26] = {0}; // 26 letters
        for (char c : magazine) {
            count[c - 'a']++; // 'a' is 97, 'b' is 98, etc. Store the count of each letter
        }
        for (char c : ransomNote) {
            if (count[c - 'a'] == 0) { // if the letter is not in magazine (i.e. count is 0)
                return false;
            }
            count[c - 'a']--; // decrement the count of the letter
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
