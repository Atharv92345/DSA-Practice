//Leetcode 141 - Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode* temp = head;
        ListNode* express = head;
        while(express->next != nullptr && express->next->next != nullptr){
            temp = temp->next;
            express = express->next->next;
            if(temp == express){
                return true;
            }
        }
        return false;
    }
};
