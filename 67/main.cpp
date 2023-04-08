#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        std::string res;

        while(i >= 0 || j >= 0 || carry){
            if(i >= 0) carry += a[i--] - '0';
            if(j >= 0) carry += b[j--] - '0';

            res += (carry % 2 + '0'); // 0 + '0' = '0', 1 + '0' = '1'
            carry /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    Solution s;
    std::string a = "11";
    std::string b = "1";
    std::cout << s.addBinary(a, b) << std::endl;

    return 0;
}
