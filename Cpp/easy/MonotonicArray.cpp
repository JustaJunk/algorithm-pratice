//#####################################################
//
//	Monotonic Array
//
//#####################################################
using namespace std;
#include <vector>

bool isMonotonic(vector<int> array)
{
	if (array.size() < 3)
		return true;

	bool isMono = true;
	auto iter = array.begin()+1;

	while (iter != array.end() && *iter == *(iter-1))
	{
		++iter;
	}
	
	if (iter == array.end())
		return true;

	if (*iter > *(iter-1))
	{
		while (iter != array.end())
		{
			if (*iter < *(iter-1))
				return false;
			++iter;
		}
		return true;
	}
	else
	{
		while (iter != array.end())
		{
			if (*iter > *(iter-1))
				return false;
			++iter;
		}
		return true;
	}
}
