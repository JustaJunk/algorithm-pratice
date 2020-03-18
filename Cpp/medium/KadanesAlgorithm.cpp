//#####################################################
//
//	Kadane's Algorithm
//
//#####################################################
#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array)
{
	int maxEndingHere = 0;
	int maxSoFar = array[0];

	for (int i = 0; i < array.size(); ++i)
	{
		if (maxEndingHere > 0)
			maxEndingHere += array[i];
		else
			maxEndingHere = array[i];

		if (maxEndingHere > maxSoFar)
			maxSoFar = maxEndingHere; 
	}

	return maxSoFar;
}

