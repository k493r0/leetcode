#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        // Floyd's cycle-finding algorithm
        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // increment slow by 1
            fast = fast->next->next; // increment fast by 2
            if (slow == fast) { // if the two ever meet, there is a cycle
                return true;
            }
        }

        return false;
    }
};


int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next->next = new ListNode(10);
    head->next->next->next->next->next->next->next->next->next->next = head->next->next->next->next;

    Solution s;
    std::cout << s.hasCycle(head) << std::endl;

    return 0;
}
