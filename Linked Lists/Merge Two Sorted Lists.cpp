//Leetcode - 21
//https://leetcode.com/problems/merge-two-sorted-lists/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        ListNode dummy(0);
        ListNode* ans = &dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1->val > temp2->val){
                ans->next = temp2;
                temp2 = temp2->next;
            }else{
                ans->next = temp1;
                temp1 = temp1->next;
            }
            ans = ans->next;
        }
        while(temp1 != nullptr){
            ans->next = temp1;
            temp1 = temp1->next;
            ans = ans->next;
        }

        while(temp2 != nullptr){
            ans->next = temp2;
            temp2 = temp2->next;
            ans = ans->next;
        }
        return dummy.next;
    }
};
