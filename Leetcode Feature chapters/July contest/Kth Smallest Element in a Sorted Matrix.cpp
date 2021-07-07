//good test case - 
//[[1,2],[1,3]]
//2
//Output:
//1

/*class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //add elements to max heap of size k
        //head is kth smallest
        priority_queue<int> pq;
        
        int numOfRows = matrix.size(), numOfCols = matrix[0].size();
        for(int i=0; i<numOfRows; i++)
        {
            for(int j=0; j<numOfCols; j++) 
            {
                pq.push(matrix[i][j]);
                if(pq.size() > k) pq.pop();
            }
        }
        
        return pq.top();
    }
};*/

class Solution{
public:
    struct compare
    {
        bool operator()(const pair<int, pair<int,int> > &a, const pair<int, pair<int,int> > &b)
        {
            return a.first > b.first; //min heap hence greater
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //make a min heap pointing to the k lists (k rows) or rather min(k,n) as if k is 5th smallest and n=100 rows we jsut need to check max till 5th row but note that k can be > n and < n^2.
        //we make min not max heap as in every iteration we move the ptr forward for the smallest element
        //think of merging 2 arrays - how pointers move.
        
        int r = matrix.size(), c = matrix[0].size();
        int heapSize = min(k,r);
        //heap elements are a triplet value of (element, row, col)
        priority_queue< pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, compare> pq;
        
        for(int i=0; i<heapSize; i++)
        {
            pq.push(make_pair(matrix[i][0], make_pair(i, 0)));
        }
            
        int count = 1; //have to pop from heap the smallest element (k-1) times so that the kth time the top element is the answer
        while(count < k)
        {
            int currRow = pq.top().second.first, currCol = pq.top().second.second;
            pq.pop();
            
            //if more elements in the popped row then point to next element and add to heap
            currCol++;
            if(currCol != c) pq.push(make_pair(matrix[currRow][currCol], make_pair(currRow, currCol)));
            
            count++;
        }
        
        return pq.top().first;
    }
};