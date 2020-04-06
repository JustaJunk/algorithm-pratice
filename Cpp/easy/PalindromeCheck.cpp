//#####################################################
//
//	Palindrome Check
//
//#####################################################
using namespace std;

bool isPalindrome(string str)
{
	if (str.empty())
		return true;

	int left = 0;
	int right = (int)str.size()-1;

	while (left < right)
	{
		if (str[left] == str[right])
		{
			left++;
			right--;
		}
		else
			return false;
	}
	return true;
}
