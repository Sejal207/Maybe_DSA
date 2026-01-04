// Given the head of a singly linked list, reverse the list, and return the reversed list.
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; 
            curr->next = prev;              
            prev = curr;                    
            curr = nextTemp;                
        }
        return prev;
    }
};
int main() {
    Solution sol;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversedHead = sol.reverseList(head);

    cout << "Reversed linked list: ";
    ListNode* curr = reversedHead;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    curr = reversedHead;
    while (curr != nullptr) {
        ListNode* nextTemp = curr->next;
        delete curr;
        curr = nextTemp;
    }

    return 0;
}