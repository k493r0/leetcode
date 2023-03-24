#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack; // Using stack
        for (auto character:s){
            switch(character){
                case '(':
                    stack.push(')'); // Append the closing parentheses to stack
                    break;
                case '[':
                    stack.push(']');
                    break;
                case '{':
                    stack.push('}');
                    break;
                default:
                    if (stack.empty() or stack.top() != character){ // If the top of the stack is not equal to character (closing parenthesis of stack.top()), it's already invalid -> early exit
                        return false;
                    }
                    stack.pop(); // After adding the closing parentheses to stack, when current(character) = end parentheses, it will pop it off the stack.
            }
        }
        return stack.empty(); // If stack is empty, all the parentheses were matched and popped off the stack, otherwise there is an unmatched parentheses
    }
};

int main() {

    Solution solution;

    std::cout << solution.isValid("()") << std::endl;
    std::cout << solution.isValid("()[]{}") << std::endl;
    std::cout << solution.isValid("(]") << std::endl;

    return 0;
}
