#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head != nullptr || head->next != nullptr) {
            return head;
        }

        ListNode* node = reverseList(head->next); // Recurse to the end of the list
        head->next->next = head; // Reverse the pointer
        head->next = nullptr;
        return node;
    }
};

int main() {

    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversed = s.reverseList(head);

    while (reversed != nullptr) {
        std::cout << reversed->val << std::endl;
        reversed = reversed->next;
    }

    return 0;
}
