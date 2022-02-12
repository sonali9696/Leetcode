/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL) return NULL;
        
        linkSibling(root, NULL);
        
        return root;
    }
    
    void linkSibling(Node* leftNode, Node* rightNode)
    {
        if(leftNode == NULL) return;
        
        if(rightNode == NULL) leftNode->next = NULL;
        else leftNode->next = rightNode;
        
        linkSibling(leftNode->left, leftNode->right);
        if(rightNode != NULL) linkSibling(leftNode->right, rightNode->left);
        else linkSibling(leftNode->right, NULL);
        //rightNode's left and right will be taken care when rightNode becomes leftNode in one of the func calls
    }
};

/*class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root == NULL) return NULL;
        
        q.push(root);
        q.push(NULL); //null is a delimiter added after nodes of every level to separate it from next level
        
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            if(q.front() == NULL) curr->next = NULL;
            else curr->next = q.front();
            
            if(curr->left != NULL) q.push(curr->left);            
            if(curr->right != NULL) q.push(curr->right);
            
            if(q.front() == NULL)
            {
                q.pop();
                if(!q.empty()) q.push(NULL); //the children's level is finished, so to start next level
            }   
        }
        
        return root;
    }
};*/