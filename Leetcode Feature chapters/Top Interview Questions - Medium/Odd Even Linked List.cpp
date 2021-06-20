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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* headEven = head->next; //head of even indices nodes
        
        ListNode *p = head, *q = headEven;
        ListNode *tailOdd;
        if(q == NULL) return head; //0 or 1 element in linked list
        
        while(p != NULL && q != NULL)
        {
            p->next = q->next;
            if(q->next != NULL) q->next = q->next->next;
            
            if(p->next == NULL) tailOdd = p;
            p = p->next;
            q = q->next;
        }
        
        //handle last node - take test case
        
        //attach headEven to tail of odd indices
        if(p != NULL) tailOdd = p;
        tailOdd->next = headEven;
        
        return head;
    }
};