//#####################################################
//
//	Number Of Ways To Make Change
//
//#####################################################
#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms)
{
	if (n < 0)
		return 0;

	vector<int> waysForN(n+1, 0);
	waysForN[0] = 1;

	for (int d : denoms)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (d <= i)
				waysForN[i] += waysForN[i-d];
		}
	}

	return waysForN[n];
}
