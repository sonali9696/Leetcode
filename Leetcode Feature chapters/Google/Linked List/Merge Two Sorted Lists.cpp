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
        ListNode*head;
        ListNode *p = l1, *q = l2;
        
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        if(l1->val <= l2->val) 
        {
            head = l1;
            p = p->next;
        }
        else 
        {
            head = l2;
            q = q->next;
        }

        ListNode *curr = head;

        while(p && q)
        {
            if(p->val <= q->val) 
            {
                curr->next = p;
                curr = p;
                p = p->next;
            }
            else
            {
                curr->next = q;
                curr = q;
                q = q->next;
            }
        }        

        if(p) curr->next = p;
        if(q) curr->next = q;

        return head;
    }


};