//#####################################################
//
//	Depth First Search
//
//#####################################################
#include <vector>
using namespace std;

class Node 
{
public:
	string name;
	vector<Node *> children;

	Node(string str) 
	{ 
		this->name = str;
	}

	vector<string> depthFirstSearch(vector<string> *array)
	{
		array->push_back(this->name);
		for (auto child = this->children.begin(); child != this->children.end(); child++)
		{
			(*child)->depthFirstSearch(array);
		}
		return *array;
	}

	Node *addChild(string name)
	{
		Node *child = new Node(name);
		children.push_back(child);
		return this;
	}
};
