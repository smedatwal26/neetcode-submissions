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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int c=0;
        ListNode* cur = dummy;
        while(l1!=NULL || l2!=NULL ||c !=0){
            int v1 = l1!=NULL ?l1->val : 0;
            int v2 = l2!=NULL ?l2->val : 0;
            int sum = v1 + v2 + c;
                c=sum/10;
                sum= sum%10;
            cur->next = new ListNode(sum);
            cur = cur->next;
            l1 = (l1!=NULL) ? l1->next : NULL;
            l2 = (l2!=NULL) ? l2->next : NULL;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
