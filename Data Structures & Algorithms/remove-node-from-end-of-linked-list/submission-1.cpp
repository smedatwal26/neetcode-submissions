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
    int rec(ListNode* node, int n){
        if(!node){
            return 0;
        }
        int c = rec(node->next,n);
        if(c == n){
            if(node ->next->next){
            node -> next = node->next->next;
            } else{
                node-> next = NULL;
            }
        }
        return c+1;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(rec(head,n) == n){
           return head->next;
        } 
            return head;
    }
};
