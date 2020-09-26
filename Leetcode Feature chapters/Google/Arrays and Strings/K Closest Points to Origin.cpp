
class Point
{
    public:
        int x,y,sumOfSquares;

        Point(int x1, int y1)
        {
            x = x1;
            y = y1;
            sumOfSquares = pow(x,2) + pow(y,2);
        }

};


struct CompareSquares
{
    bool operator()(Point const& p1, Point const& p2){
        return p1.sumOfSquares < p2.sumOfSquares;
    }
};



class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        //sqrt(x^2 + y^2)is smallest means x^2 + y^2 is smallest

        priority_queue<Point, vector<Point>,CompareSquares> pq; //max heap of x^2 + y^2.

        int n = points.size();
        vector<vector<int>> kClosestPoints;

        for(int i=0; i<n; i++)
        {
            pq.push(Point(points[i][0],points[i][1]));

            if(pq.size() > K) pq.pop();
        }

        //heap contains K smallest values
        while(!pq.empty())
        {
            Point p = pq.top();
            kClosestPoints.push_back({p.x,p.y});
            pq.pop();
        }
        
        
        return kClosestPoints;
    }
    

};