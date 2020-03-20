//#####################################################
//
//	Branch Sum
//
//#####################################################
using namespace std;

class BinaryTree 
{
public:
	int value;
	BinaryTree *left;
	BinaryTree *right;

	BinaryTree(int value) {
		this->value = value;
		this->left = NULL;
		this->right = NULL;
	}
};

void branchAdder(BinaryTree 	*node,
				 int 			preSum,
				 vector<int> 	&sumVec);

vector<int> branchSums(BinaryTree *root) {

	vector<int> sumVec;

	branchAdder(root, 0, sumVec);

	return sumVec;
}

void branchAdder(BinaryTree 	*node,
				 int 			preSum,
				 vector<int> 	&sumVec)
{
	if (!node)
		return;

	int nodeSum = preSum + node->value;

	if (node->left == NULL && node->right == NULL)
	{
		sumVec.push_back(nodeSum);
		return;
	}

	branchAdder(node->left, nodeSum, sumVec);
	branchAdder(node->right, nodeSum, sumVec);
}
