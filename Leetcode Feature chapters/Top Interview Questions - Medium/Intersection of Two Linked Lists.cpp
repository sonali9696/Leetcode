/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //get length of the two: after intersection length is common
        //before that the difference of the lengths will tell which is bigger and by how much
        
        int lenA = 0, lenB = 0;
        ListNode* ptr = headA;
        while(ptr != NULL)
        {
            lenA++;
            ptr = ptr->next;
        }
        ptr = headB;
        while(ptr != NULL)
        {
            lenB++;
            ptr = ptr->next;
        }
        
        ListNode *p, *q;
        
        if(lenA >= lenB)
        {
            p = headA, q = headB;
            int diff = lenA-lenB;
            while(diff != 0)
            {
                p = p->next;
                diff--;
            }
        }
        else {
            p = headB, q = headA;
            int diff = lenB-lenA;
            while(diff != 0) {
                p = p->next;
                diff--;
            }
        }
           
        //now they are equidistant from intersection point
        while(p != NULL && q != NULL && p != q)
        {
            p = p->next;
            q = q->next;
        }

        if(p == NULL || q == NULL) return NULL;
        else return p;
    }
};