//#####################################################
//
//	Smallest Different
//
//#####################################################
#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallestDifference( vector<int> arrayOne, 
								vector<int> arrayTwo)
{
	if (arrayOne.empty() || arrayTwo.empty())
		return {};

	sort(arrayOne.begin(), arrayOne.end());
	sort(arrayTwo.begin(), arrayTwo.end());

	auto 	iter1 = arrayOne.begin();
	auto 	iter2 = arrayTwo.begin();
	int 	curDiff;
	int 	minDiff = abs(*iter1 - *iter2);
	vector<int> minPair;

	while (	iter1 != arrayOne.end() &&
			iter2 != arrayTwo.end() )
	{
		curDiff = abs(*iter1 - *iter2);
		if (curDiff == 0)
			return {*iter1, *iter2};
		else if (curDiff < minDiff)
		{
			minDiff = curDiff;
			minPair = {*iter1, *iter2};
		}

		if (*iter1 > *iter2)
			iter2++;
		else
			iter1++;
	}

	return minPair;
}
