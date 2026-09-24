/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* h = &dummy;
        while(l1 && l2){
            if(l1->val >= l2->val){
                if(!h){
                    h = l2;
                } else {
                    h->next = l2;
                }
                l2 = l2->next;
            } else {
                if(!h){
                    h =l1;
                } else {
                    h->next = l1;
                }
                l1 = l1 -> next;
            }
            h = h -> next;
        }
        if(l1){
            h -> next = l1;
        } else {
            h -> next = l2;
        }
         return dummy.next;
    }
};
