//#####################################################
//
//	Water Area
//
//#####################################################
#include <vector>
using namespace std;

int waterArea(vector<int> heights)
{
	if (heights.size() < 3)
		return 0;

	size_t pillarNum = heights.size();

	vector<int> leftMax(pillarNum);
	vector<int> rightMax(pillarNum);
	int 		waterLevel;
	int 		waterLevelSum = 0;

	leftMax[0] = 0;
	for (int i = 1; i < pillarNum; ++i)
		leftMax[i] = (heights[i-1] > leftMax[i-1])? heights[i-1] : leftMax[i-1];

	rightMax[pillarNum-1] = 0;
	for (int i = pillarNum-2; i >= 0; --i)
		rightMax[i] = (heights[i+1] > rightMax[i+1])? heights[i+1] : rightMax[i+1];

	for (int i = 0; i < pillarNum; ++i)
	{
		waterLevel = (leftMax[i] > rightMax[i])? rightMax[i] : leftMax[i];
		waterLevelSum += (waterLevel > heights[i])? waterLevel - heights[i] : 0;
	}

	return waterLevelSum;

}
