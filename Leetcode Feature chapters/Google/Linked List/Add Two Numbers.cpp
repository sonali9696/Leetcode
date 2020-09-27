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
        ListNode *p = l1, *q = l2;


        int total = p->val + q->val;
        int carry = total/10;
        total = total % 10;
        ListNode *sum = new ListNode(total);
        ListNode * curr = sum;
        p = p->next;
        q = q->next;

        while(p != NULL && q != NULL)
        {
            total = p->val + q->val + carry;
            carry = total/10;
            total = total % 10;
            ListNode *temp = new ListNode(total);
            curr->next = temp;
            curr = temp;
            p = p->next;
            q = q->next;
        }

        while(p)
        {
            total = p->val + carry;
            carry = total/10;
            total = total % 10;
            ListNode *temp = new ListNode(total);
            curr->next = temp;
            curr = temp;
            p = p->next;
        }

        while(q)
        {
            total = q->val + carry;
            carry = total/10;
            total = total % 10;
            ListNode *temp = new ListNode(total);
            curr->next = temp;
            curr = temp;
            q = q->next;
        }

        if(carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }


        return sum;   
    }


};