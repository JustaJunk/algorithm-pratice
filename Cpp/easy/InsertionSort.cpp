//#####################################################
//
//	Insertion Sort
//
//#####################################################
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array)
{
	int sortedNum = 0;
	while (++sortedNum < array.size())
	{
		auto insertIter = array.begin()+sortedNum;
		while (	insertIter != array.begin() &&
				*insertIter < *(insertIter-1))
		{
			iter_swap(insertIter, --insertIter);
		}
	}
	return array;
}
