//#####################################################
//
//	Bubble Sort
//
//#####################################################
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array)
{
	if (array.empty())
		return array;

	int  topNum = 0;
	while(topNum != array.size()-1)
	{
		for (auto iter = array.begin(); iter != array.end()-1-topNum; ++iter)
		{
			if (*iter > *(iter+1))
				iter_swap(iter, iter+1);
		}
		topNum++;
	}
	return array;
}
