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
	
	for (int d : denoms)
	{
		for (int i = 1; i <= n; ++i)	
		{
			if (d <= i)
			{
				int &currentMin = minCoinsForN[i];
				subResult = minCoinsForN[i-d];
				if (subResult != -1 && 
					(currentMin == -1 || subResult+1 < currentMin))
					currentMin = subResult+1;
			}
		}
	}	
	return minCoinsForN[n];
}