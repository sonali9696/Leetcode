class DetectSquares {
public:
    unordered_map<int, unordered_map<int, int>> PointsInThisCol; //col, row, freq
    
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        PointsInThisCol[y][x]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0], y1 = point[1];
        
        //get all points on with y=y1 having a different x to get one side of the square
        unordered_map <int, int> otherPoints = PointsInThisCol[y1];
        
        int numSquares = 0;
        
        unordered_map <int, int>::iterator it;
        for(it = otherPoints.begin(); it != otherPoints.end(); ++it)
        {
            int x2 = it->first, freq = it->second;
            
            //the point shouldn't be itself
            if(x2 == x1) continue;
            
            //find length of side, this should be maintained on all sides for square
            int lenOfSide = abs(x2 - x1);
            
            //find if other points exist for the square
            //this would be at a different y
            //this new y could be above or below current y but lenOfSide should be same 
            //i.e. y2 = y1 + lenOfSide or y2 = y1 - lenOfSide
            
            if(PointsInThisCol[y1 + lenOfSide][x1] && PointsInThisCol[y1 + lenOfSide][x2]) 
            {
                numSquares += (freq * PointsInThisCol[y1 + lenOfSide][x1] * PointsInThisCol[y1 + lenOfSide][x2]);    
            }
            
            if(PointsInThisCol[y1 - lenOfSide][x1] && PointsInThisCol[y1 - lenOfSide][x2]) 
            {
                numSquares += (freq * PointsInThisCol[y1 - lenOfSide][x1] * PointsInThisCol[y1 - lenOfSide][x2]);     
            }
            
        }
        
        return numSquares;
    }
};

