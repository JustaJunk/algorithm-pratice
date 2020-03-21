//#####################################################
//
//	Selection Sort
//
//#####################################################
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array)
{
	int sortedNum = 0;
	int n = (int)array.size();
	while (sortedNum < n)
	{
		auto startIter = array.begin()+sortedNum;
		auto minIter = startIter;
		int  minValue  = *minIter;
		for (auto iter = startIter; iter != array.end(); iter++)
		{
			if (*iter < minValue)
			{
				minValue = *iter;
				minIter = iter;
			}
		}
		iter_swap(minIter, startIter);
		sortedNum++;
	}
	return array;
}
