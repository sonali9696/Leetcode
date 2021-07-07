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

//More optimal - 
/*class Solution{
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
};*/

//Most optimal - binary search (not over index but over values of left top corner and right bottom corner)
class Solution{
private:
    int findElementSmallerThanMid(vector<vector<int>>& matrix, int mid, int &L, int &R)
    {
        int n = matrix.size();
        int row = n-1, col = 0;
        L = matrix[0][0], R = matrix[n-1][n-1];
        int leftHalfSize = 0;
        while(row >= 0 && col < n)
        {
            if(matrix[row][col] <= mid) 
            {
                L = max(L, matrix[row][col]);
                leftHalfSize += (row+1);
                col++;
            }
            else
            {
                R = min(R, matrix[row][col]);
                row--;
            }
        }
        
        return leftHalfSize;
    }
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); //not matrix is n*n not m*n i.e. #rows=#cols
        
        int low = matrix[0][0], high = matrix[n-1][n-1];
        //in normal sorted array, arr[k] would be kth smallest so here we are finding 
        //till we have left half size = k s.t. last element in that left half is ans
        
        while(low < high)
        {
            int mid = low + (high-low)/2;
            int L, R;
            int leftHalfSize = findElementSmallerThanMid(matrix, mid, L, R);
            
            if(leftHalfSize == k) return L;
            else if(leftHalfSize < k) low = R;
            else high = L;
        }
        
        return low;
    }


};
