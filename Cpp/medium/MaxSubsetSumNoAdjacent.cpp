//#####################################################
//
//	Max Subset Sum No Adjacent
//
//#####################################################
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array)
{
	if (array.empty())
		return 0;

	int maxSum;
	int maxSum1 = 0;
	int maxSum2 = 0;

	for (int number : array)
	{
		if (maxSum2 + number > maxSum1)
			maxSum = maxSum2 + number;
		else
			maxSum = maxSum1;

		maxSum2 = maxSum1;
		maxSum1 = maxSum;
	}
	return maxSum;
}
