#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        // Two pointers approach
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !isalnum(s[start])) { // move start pointer to the next alphanumeric character
                start++;
            }
            while (start < end && !isalnum(s[end])) { // move end pointer to the previous alphanumeric character
                end--;
            }
            if (tolower(s[start++]) != tolower(s[end--])) { // compare characters and return immediately if they are not equal
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    std::cout << s.isPalindrome("race a car") << std::endl;
    return 0;
}
