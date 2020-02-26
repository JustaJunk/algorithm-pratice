#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum)
{
	int leftIdx  = 0;
	int rightIdx = array.size()-1;
	int currentSum;
	sort(array.begin(), array.end());

	while (leftIdx < rightIdx)
	{
		currentSum = array[leftIdx] + array[rightIdx];
		if 		(currentSum < targetSum) 	leftIdx++;
		else if (currentSum > targetSum) 	rightIdx--;
		else return {array[leftIdx], array[rightIdx]}; 
	}

	return {};
}