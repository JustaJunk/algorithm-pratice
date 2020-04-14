//#####################################################
//
//	Merge Linked Lists
//
//#####################################################
#include <vector>
using namespace std;

class LinkedList
{
public:
	int value;
	LinkedList *next;

	LinkedList(int value)
	{
		this->value = value;
		next = nullptr;
	}
};

LinkedList *mergeLinkedLists(LinkedList *head1, LinkedList *head2)
{
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;

	LinkedList* head;
	LinkedList* current;
	LinkedList* next1;
	LinkedList* next2;
	
	if (head1->value <= head2->value)
	{
		current = head = head1;
		next1 = head1->next;
		next2 = head2;
	}
	else
	{
		current = head = head2;
		next1 = head1;
		next2 = head2->next;
	}

	while (true)
	{
		if (next1 == nullptr)
		{
			current->next = next2;
			break;
		}

		if (next2 == nullptr)
		{
			current->next = next1;
			break;
		}

		if (next1->value <= next2->value)
		{
			current = current->next = next1;
			next1 = next1->next;
		}
		else
		{
			current = current->next = next2;
			next2 = next2->next;
		}
	}

	return head;
}
