//Leetcode 328 - Odd Even Linked List
//https://leetcode.com/problems/odd-even-linked-list/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = slow->next;
        while(fast != nullptr && fast->next != nullptr){
            ListNode* temp = fast->next;
            fast->next = temp->next;
            temp->next = slow->next;
            slow->next = temp;
            
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};
