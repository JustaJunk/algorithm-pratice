//#####################################################
//
//	Min Number Of Coins For Change
//
//#####################################################
#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
	if (n < 0)
		return -1;

	vector<int> minCoinsForN(n+1, -1); //--- -1 stands for infinity
	minCoinsForN[0] = 0;
	int subResult;
	for (int d = 0; d < denoms.size(); ++d)
	{
		for (int i = 1; i <= n; ++i)	
		{
			if (denoms[d] <= i)
			{
				subResult = minCoinsForN[i-denoms[d]];
				if (subResult != -1 && 
					(minCoinsForN[i] == -1 || subResult+1 < minCoinsForN[i]))
					minCoinsForN[i] = subResult+1;
			}
		}
	}	
	return minCoinsForN[n];
}