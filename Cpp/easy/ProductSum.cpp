//#####################################################
//
//  Product Sum
//
//#####################################################
#include <any>
#include <vector>

using namespace std;

int productSum(	vector<any> array,
				int 		multiplier = 1)
{
	int sum = 0;
	for (auto sth : array)
	{
		if (sth.type() == typeid(vector<any>))
			sum += productSum(any_cast<vector<any>>(sth), multiplier+1);
		else
			sum += any_cast<int>(sth);
	}	
	return sum*multiplier;
}