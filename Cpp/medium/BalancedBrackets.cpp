//#####################################################
//
//	Balanced Brackets
//
//#####################################################
#include <vector>
#include <unordered_map>
using namespace std;

bool balancedBrackets(string str)
{
	const string leftBrackets 	= "([{";
	const string rightBrackets 	= ")]}";
	const unordered_map<char, char> matchBracket
	{
		{')', '('}, 
		{']', '['}, 
		{'}', '{'}
	};
	vector<char> stack;

	for (char letter:str)
	{
		if (leftBrackets.find(letter) != string::npos)
		{
			stack.push_back(letter);
		}
		else if (rightBrackets.find(letter) != string::npos)
		{
			if (stack.empty())
				return false;

			if (stack.back() == matchBracket.at(letter))
				stack.pop_back();
			else
				return false;
		}
	}

	return stack.empty();
}
