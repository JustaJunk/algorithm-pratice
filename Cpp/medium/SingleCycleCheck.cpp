//#####################################################
//
//	Single Cycle Check
//
//#####################################################
using namespace std;

bool hasSingleCycle(vector<int> array)
{
	int n = (int)array.size();
	int idx = array[0] < 0 ? n+array[0]%n : array[0]%n;
	for (int i = 0; i < n-1; ++i)
	{
		if (idx == 0)
			return false;

		idx = (idx + array[idx])%n;
		if (idx < 0)
			idx += n;
	}
	return idx == 0;
}
