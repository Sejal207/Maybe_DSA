// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. Write a function that takes in the heads of the two linked lists and returns the head of the new linked list representing the sum.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 #include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1, *q = l2, *current = dummyHead;
        int carry = 0;

        while (p != nullptr || q != nullptr) {
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;

            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }

        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        return dummyHead->next;
    }
};
int main() {
    Solution sol;

    // Create first linked list: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = sol.addTwoNumbers(l1, l2);

    // Print the resulting linked list
    cout << "Resulting linked list: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}


