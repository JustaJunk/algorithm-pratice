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
	while (sortedNum < array.size())
	{
		auto startIter = array.begin()+sortedNum;
		auto minIter = startIter;
		int  minValue  = *minIter;
		for (auto iter = startIter; iter != array.end(); ++iter)
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

vector<int> selectionSort2(vector<int> array)
{
	auto endIter = array.end();
	for (auto iter = array.begin(); iter != endIter; ++iter)
		iter_swap(iter, min_element(iter, endIter));
	return array;
}
