//#####################################################
//
//	Longest Palindromic Substring
//
//#####################################################
using namespace std;

struct StrBound
{
	int	start;
	int length;

	StrBound()
	: start{0}, length{1}
	{}

	StrBound(int s, int l)
	: start{s}, length{l}
	{}
};

StrBound expandPalindrome(	string 	&targetStr,
					  		int 	leftInit,
					  		int 	rightInit);

string longestPalindromicSubstring(string str)
{
	StrBound longest;
	StrBound odd;
	StrBound even;

	for (int i = 0; i < str.size(); ++i)
	{
		odd = expandPalindrome(str, i-1, i+1);
		even = expandPalindrome(str, i-1, i);

		if (odd.length > longest.length)
			longest = odd;

		if (even.length > longest.length)
			longest = even;
	}

	return str.substr(longest.start, longest.length);
}


StrBound expandPalindrome(	string 	&targetStr,
					  		int 	leftInit,
					  		int 	rightInit)
{
	while(leftInit >= 0 && rightInit < targetStr.size())
	{
		if (targetStr[leftInit] != targetStr[rightInit])
			break;

		--leftInit;
		++rightInit;
	}

	return StrBound(leftInit+1, rightInit-leftInit-1);
} 