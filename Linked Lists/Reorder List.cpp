//Leetcode 143 - Reorder List
//https://leetcode.com/problems/reorder-list/description/

class Solution {
public:
    ListNode* reversal(ListNode* slow){
        ListNode* curr = slow;
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

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reversed = reversal(slow->next);
        slow->next = nullptr;
        ListNode* temp = reversed;
        ListNode* fixed = head;
        while(temp != nullptr){
            ListNode* l1 = fixed->next;
            ListNode* l2 = temp->next;
            temp->next = fixed->next;
            fixed->next = temp;
            temp = l2;
            fixed = l1;
        }
        return;
    }
};
