//#####################################################
//
//	Move Element To End
//
//#####################################################
#include <vector>
using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove)
{
	if (array.empty())
		return {};
	
	auto leftIter = array.begin();
	auto rightIter = array.end()-1;

	while (leftIter != rightIter)
	{
		if (*rightIter == toMove)
			rightIter--;
		else if (*leftIter != toMove)
			leftIter++;
		else
		{
			iter_swap(leftIter, rightIter);
			leftIter++;
			rightIter--;
		}
	}

	return array;
}