#include <iostream>
#include <stack>

class MyQueue {
public:
    MyQueue() {
        stackIn = std::stack<int>();
        stackOut = std::stack<int>();
    }

    void push(int x) {
        stackIn.push(x);
    }

    int pop() {
        peek();
        const int top = stackOut.top();
        stackOut.pop();
        return top;
    }

    int peek() {
        if (stackOut.empty()) {
            while (!stackIn.empty()) {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        return stackOut.top();
    }

    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
private:
    std::stack<int> stackIn;
    std::stack<int> stackOut;
};

int main() {

    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << queue.peek() << std::endl;
    queue.pop();
    std::cout << queue.peek() << std::endl;
    queue.pop();
    std::cout << queue.peek() << std::endl;
    queue.pop();

    std::cout << queue.empty() << std::endl;

    return 0;
}