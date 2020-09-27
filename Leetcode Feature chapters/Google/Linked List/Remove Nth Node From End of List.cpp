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
    int sizeOfLinkedList(ListNode* curr)
    {
        int size = 0;
        while(curr)
        {
            size++;
            curr = curr->next;
        }
        return size;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        //nth node from back = (len-n) from front if index starts at 0

        ListNode* curr = head;
        int len = sizeOfLinkedList(curr);
        int goalIndex = len - n;
        if(goalIndex > 0)
        {
            for(int i=0; i<goalIndex-1;i++) curr = curr->next;  
            curr->next = curr->next->next; 
        }
        else if(goalIndex == 0)
        {
            head = head->next;
        }
        else return NULL;
        
        return head;
    }
    
};