//Leetcode 19 - Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
         for(int i = 0; i < n; i++){
                fast = fast->next;
            }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* temp = slow -> next;
        slow->next = slow->next->next;
        delete temp;
        return dummy.next;
    }
};
