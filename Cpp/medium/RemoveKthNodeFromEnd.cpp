//#####################################################
//
//  Remove Kth Node From End
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
	vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k)
{
	LinkedList *current = head;
	LinkedList *atherK = head;

	for (int i = 0; i < k; ++i)
	{
		if (atherK == nullptr)
			return;
		atherK = atherK->next;	
	}

	if (atherK == nullptr)
	{
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}

	while(atherK->next != nullptr)
	{
		current = current->next;
		atherK = atherK->next;
	}

	current->next = current->next->next;
}
