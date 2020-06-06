class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int type[2], lastIndex[2], fruitsFromTree[2];
        
        memset(type, -1, sizeof(type));
        memset(lastIndex, -1, sizeof(lastIndex));
        memset(fruitsFromTree, 0, sizeof(fruitsFromTree));
        
        int maxNumberOfFruits = 0;
        int l = tree.size();
        int indexToBeReplaced, otherIndex, removedIndex;
        
        for(int i = 0; i < l; i++)
        {
            if (tree[i] == type[0])
            {
                lastIndex[0] = i;
                fruitsFromTree[0]++;
            }
            else if(tree[i] == type[1])
            {
                lastIndex[1] = i;
                fruitsFromTree[1]++;
            }
            else
            {
                
                indexToBeReplaced = (lastIndex[0] < lastIndex[1]) ? 0 : 1;
                type[indexToBeReplaced] = tree[i];
                removedIndex = lastIndex[indexToBeReplaced]; 
                lastIndex[indexToBeReplaced] = i;
                fruitsFromTree[indexToBeReplaced] = 1;
                
                otherIndex = 1 - indexToBeReplaced;
                if(lastIndex[otherIndex] != -1)
                {
                    //number remaining should be from removedIndex+1 till (i-1)
                    fruitsFromTree[otherIndex] = (i-1) - removedIndex;
                }
            }
            
            if(fruitsFromTree[0] + fruitsFromTree[1] > maxNumberOfFruits) 
                maxNumberOfFruits = fruitsFromTree[0] + fruitsFromTree[1];
        }
        
        return maxNumberOfFruits;
        
    }
};