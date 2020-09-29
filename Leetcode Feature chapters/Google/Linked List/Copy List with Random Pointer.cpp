/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* headOfDeepCopy = new Node(head->val);
        Node *ptr1 = head, *ptr2 = headOfDeepCopy; 
        //can’t do next,random as same as the copy can’t point to the nodes in the original

        if(ptr1->random == NULL) ptr2->random = NULL;

        vector<Node*> pointerToNodesInCopy;
        map<Node*,int> IndexOfNodes;
        pointerToNodesInCopy.push_back(ptr2);
        IndexOfNodes[ptr1] = 0;
        int index = 0;

        while(ptr1->next != NULL)
        {
            Node* newNode = new Node((ptr1->next)->val);
            ptr2->next = newNode;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            pointerToNodesInCopy.push_back(ptr2);
            IndexOfNodes[ptr1] = ++index;

            if(ptr1->random == NULL) ptr2->random = NULL;
        }

        //reset to populate non-null random
        ptr1 = head, ptr2 = headOfDeepCopy;

        while(ptr1 != NULL)
        {
            if(ptr1->random == NULL) 
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                continue;
            }

            int randomNodeIndex = IndexOfNodes[ptr1->random];
            ptr2->random = pointerToNodesInCopy[randomNodeIndex];

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }


        return headOfDeepCopy;
    }
};
