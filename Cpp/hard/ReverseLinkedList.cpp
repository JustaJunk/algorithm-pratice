//#####################################################
//
//	Reverse Linked List
//
//#####################################################
using namespace std;

class LinkedList 
{
public:
	int value;
	LinkedList *next;

	LinkedList(int value)
	{
		this->value = value;
		this->next = nullptr;
	}
};

LinkedList *reverseLinkedList(LinkedList *head)
{
	if (head == nullptr)
		return nullptr;

	LinkedList* current = head;
	LinkedList* prevOne = nullptr;
	LinkedList* nextOne = head->next;

	while (nextOne)
	{
		current->next = prevOne;
		prevOne = current;
		current = nextOne;
		nextOne = current->next;
	}

	current->next = prevOne;

	return current;
}
