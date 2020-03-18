//#####################################################
//
//	Binary Search
//
//#####################################################
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
	if (array.empty())
		return -1;

	int left = 0;
	int right = (int)array.size()-1;
	int current;
	while (left <= right)
	{
		current = (left+right)/2;
		if (array[current] == target)
			return current;
		else if (array[current] > target)
			right = current-1;
		else
			left = current+1;
	}
	return -1;
}
