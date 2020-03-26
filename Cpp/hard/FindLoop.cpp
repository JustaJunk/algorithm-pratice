//#####################################################
//
//	Find Loop
//
//#####################################################
#include <vector>
using namespace std;

class LinkedList 
{
public:
	int value;
	LinkedList *next;

	LinkedList(int value);
	void addMany(vector<int> values);
	LinkedList *getNthNode(int n);
};

LinkedList *findLoop(LinkedList *head)
{
	LinkedList* 	slowerPtr = head->next;
	if (slowerPtr == nullptr)
		return nullptr;
	LinkedList* 	fasterPtr = head->next->next;
	if (fasterPtr == nullptr)
		return nullptr;

	while (slowerPtr != fasterPtr)
	{
		fasterPtr = fasterPtr->next;
		if (fasterPtr == nullptr)
			return nullptr;
		fasterPtr = fasterPtr->next;
		if (fasterPtr == nullptr)
			return nullptr;
		slowerPtr = slowerPtr->next;
	}

	fasterPtr = head;

	while (slowerPtr != fasterPtr)
	{
		slowerPtr = slowerPtr->next;
		fasterPtr  = fasterPtr->next;
	}

	return slowerPtr;
}
