#include <iostream>

bool isBadVersion(int version){
    if (version >= 5) {
        return true;
    }
    return false;
};

class Solution {
public:
    int firstBadVersion(int n) {
       int low = 0, high = n;
         while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) high = mid;
            else low = mid + 1;
         }
        return low;
    }
};

int main() {

    Solution s;
    std::cout << s.firstBadVersion(5) << std::endl;

    return 0;
}
