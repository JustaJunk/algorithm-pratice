#include <cmath>
using namespace std;

class BST
{
public:
	int value;
	BST *left;
	BST *right;

	BST(int val);
	BST &insert(int val);
};

static BST* nextBST(BST *currentBST, 
					int target,
					int &currentValue,
					int &currentAbsDiff);

int findClosestValueInBst(BST *tree, int target)
{
	if (!tree)
		return -1;

	BST *currentBST = tree;
	int currentValue = tree->value;
	int currentAbsDiff = abs(tree->value - target);

	while (currentBST)
	{
		currentBST=nextBST(	currentBST,
							target, 
							currentValue,
							currentAbsDiff);
	}
	return currentValue; 
}

static BST* nextBST(BST *currentBST, 
					int target,
					int &currentValue,
					int &currentAbsDiff)
{
	int diff = currentBST->value - target;
	if (abs(diff) < currentAbsDiff)
	{
		currentValue = currentBST->value;
		currentAbsDiff = abs(diff);
	}

	if (diff > 0)
		return currentBST->left;
	else if (diff < 0)
		return currentBST->right;
	else 
		return NULL;
}
