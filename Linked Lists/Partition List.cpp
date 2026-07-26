//Leetcode 86 - Partition List
//https://leetcode.com/problems/partition-list/description/

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        while(slow->next != nullptr && slow->next->val < x){
            slow = slow->next;
        }
        fast = slow->next;
        while(fast != nullptr && fast->next != nullptr){
            if(fast->next->val < x){
                ListNode* temp = fast->next;
                fast->next = temp->next;
                temp->next = slow->next;
                slow->next = temp;
                slow = slow->next;
            }else{
                fast = fast->next;
            }
        }
        return dummy.next;
    }
};
