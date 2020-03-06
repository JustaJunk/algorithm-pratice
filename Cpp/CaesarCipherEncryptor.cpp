//#####################################################
//
//	Caesar Cipher Encryptor
//
//#####################################################
#include <vector>
#include <numeric>
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
	vector<char> 		newLetters;
	int 				newLetter;

	for (int i = 0; i < str.length(); i++)
	{
		newLetter = str[i] + key;
		if (newLetter > 122 || newLetter < 96)
		{
			newLetter = 96 + (newLetter-96) % 26;
		}
		newLetters.push_back(newLetter);
	}
	return string(newLetters.begin(),newLetters.end());
}