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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int K = lists.size();
        if(K == 0) return NULL;

        ListNode* p[K];

        for(int i=0; i<K; i++) p[i] = lists[i];

        int smallest = INT_MAX, smallestInd = -1;
        ListNode* head;
        ListNode* curr;

        for(int i=0; i<K;i++)
        {
            if(p[i] != NULL && p[i]->val < smallest)
            {
                smallest = p[i]->val;
                smallestInd = i;
            }
        }
        
        if(smallest == INT_MAX) return NULL; //array of empty lists

        head = p[smallestInd];
        curr = p[smallestInd];
        if(p[smallestInd]  != NULL) p[smallestInd] = p[smallestInd]->next;

        while(1)
        {
            smallest = INT_MAX;
            smallestInd = -1;
            for(int i=0; i<K;i++)
            {
                if(p[i] != NULL && p[i]->val < smallest)
                {
                    smallest = p[i]->val;
                    smallestInd = i;
                }
            }

            if(smallest == INT_MAX) 
            {
                curr->next = NULL;
                break; //all lists completed
            }

            curr->next = p[smallestInd];
            curr = curr->next;
            p[smallestInd] = p[smallestInd]->next;
            
        }

        return head;
    }

};