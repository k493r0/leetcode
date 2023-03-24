#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *tail = &dummy; // Reference to dummy

        while (list1 && list2) { // Iterate through each ListNode for both list1 and list2
            if (list1->val < list2->val){ // If the value of list1 < list2, link the tail to list 1
                tail->next = list1;
                list1 = list1->next; // Reassign pointer to the next one
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next; // Link to the next one
        }

        tail->next = list1 ? list1 : list2; // Link the tail to list one if list1 is not pointing to null pointer, if list1 is point to nullptr (no values left), point to list2
        return dummy.next;

    }
};

int main() {

    Solution solution;
    ListNode *list1 = new ListNode(1);
    ListNode *list2 = new ListNode(2);
    ListNode *list3 = new ListNode(4);
    ListNode *list4 = new ListNode(1);
    ListNode *list5 = new ListNode(3);
    ListNode *list6 = new ListNode(4);

    list1->next = list2;
    list2->next = list3;
    list4->next = list5;
    list5->next = list6;

    ListNode *result = solution.mergeTwoLists(list1, list4);

    while (result != nullptr) {
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << std::endl;

    return 0;
}
