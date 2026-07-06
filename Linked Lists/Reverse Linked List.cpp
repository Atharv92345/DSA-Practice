//Leetcode 206 - Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* forward = nullptr;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};
