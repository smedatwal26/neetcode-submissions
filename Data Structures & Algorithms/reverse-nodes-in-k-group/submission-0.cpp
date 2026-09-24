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
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* dummy = new ListNode(0,head);
       ListNode* groupprev = dummy;
       while(true){
        ListNode* kth = getKth(groupprev,k);
        if(!kth)
        {
            break;
        }
        ListNode* prev = kth->next;
        ListNode* cur = groupprev->next;
        ListNode* groupnext = kth->next;
        while(cur!=groupnext){
            ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
        }
        ListNode* tmp = groupprev->next;
        groupprev->next = kth;
        groupprev = tmp;
       }
       return dummy->next;
    }
};
