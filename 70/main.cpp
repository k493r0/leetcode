#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        // Fibonacci sequence f(n) = f(n-1) + f(n-2)
        int a = 1, b = 2, c = 0; // a = f(n-2), b = f(n-1), c = f(n)
        for (int i = 3; i <= n; ++i) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {

    Solution s;
    std::cout << s.climbStairs(3) << std::endl;
    std::cout << s.climbStairs(4) << std::endl;
    std::cout << s.climbStairs(5) << std::endl;
    std::cout << s.climbStairs(6) << std::endl;

    return 0;
}
