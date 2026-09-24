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
   

   // find kth node 
   //check kth is null
   //get grouprev
   // get groupnext
   //reverse kth
   // cur = grouprev->next
    ListNode* getKth(ListNode* cur,int k){
        while(k>0 && cur){
            cur = cur->next;
            k--;
        }
        return cur;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* dummy = new ListNode(0,head);
      ListNode* grouprev = dummy;
      while(true){
        ListNode* kth = getKth(grouprev,k);
        if(!kth){
            break;
        }
        ListNode* groupnext = kth->next;
        ListNode* cur = grouprev->next;
        ListNode* prev = kth->next;
        while(cur!=groupnext){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode* temp = grouprev->next;
        grouprev->next = kth;
        grouprev = temp;
      }
      return dummy->next;
    }
};
