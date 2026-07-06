//Leetcode 234 - Palindrome Linked List
//https://leetcode.com/problems/palindrome-linked-list/description/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
        ListNode* mid = head;
        ListNode* express = head;
        while(express->next != nullptr && express->next->next != nullptr){
            mid = mid->next;
            express = express->next->next;
        }
        mid = mid->next;
        ListNode* prev = nullptr;
        ListNode* c = mid;
        ListNode* head2 = mid;
        ListNode* forward = nullptr;
        while(c != nullptr){
            forward = c->next;
            c->next = prev;
            prev = c;
            head2 = c;
            c = forward;
        }
        ListNode* temp = head;
        ListNode* temp2 = head2;
        while(temp2 != nullptr){
            if(temp->val != temp2->val){
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
};
