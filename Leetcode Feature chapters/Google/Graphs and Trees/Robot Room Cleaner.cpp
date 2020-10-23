/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
	int directions[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    //up,right,down,left

	set<pair<int,int>> visited;

public:
	void goBack(Robot& robot)
	{
		//turn back
		robot.turnRight();
        robot.turnRight();

        robot.move(); //move one cell back

        //go back to the direction it was in before
        robot.turnRight();
        robot.turnRight();
	}

	void backtrack(Robot& robot, int row, int col, int dir)
	{
        visited.insert(make_pair(row,col));
		robot.clean();
		
		//explore all directions from current pos
		for(int i=0; i<4; i++)
		{
            int newD = (dir + i) % 4;
                
			int nextRow = row + directions[newD][0];
			int nextCol = col + directions[newD][1];
            //order is imp because if visited, don't move robot
			if(visited.count(make_pair(nextRow,nextCol)) == 0 && robot.move())
			{
				backtrack(robot,nextRow,nextCol,newD);

				//robot.move moved robot in i direction 
                //so get back to original cell to explore other directions from it
				goBack(robot);
			}
			robot.turnRight();
		}
	}

    void cleanRoom(Robot& robot) {
        //defining origin at starting position
        int row = 0, col = 0, dir = 0;
        backtrack(robot,0,0,0);
    }
};

