class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        //see if pair of points can form the diagonal sides of a rectangle
        //i.e. (x1,y1) and (x2,y2) then for rectangle, (x1,y2) and (x2,y1) should exist
        //if yes, see if area is minimum.

        set<int> pointCodes;	
		int n=points.size();
		for(int i=0; i<n; i++)
		{
			int x = points[i][0], y = points[i][1];
			pointCodes.insert(40001*x+y);
		}

		int minArea = INT_MAX;
		
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(points[i][0] != points[j][0] && points[i][1] != points[j][1])
				{
					int x1 = points[i][0], x2 = points[j][0];
					int y1 = points[i][1], y2 = points[j][1];

					if(pointCodes.find(40001*x1+y2) != pointCodes.end() && 
                       pointCodes.find(40001*x2+y1) != pointCodes.end())
					{
						minArea=min(minArea,(abs(y2-y1)*abs(x2-x1)));
					}
				}
			}
		}
		
		if(minArea == INT_MAX) return 0;
		else return minArea;
    }
};

