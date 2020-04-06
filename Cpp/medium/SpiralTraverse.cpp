//#####################################################
//
//	Spiral Traverse
//
//#####################################################
using namespace std;

void pushRow(const vector<vector<int>> &matrix, vector<int> &output, int row, int from, int end);
void pushCol(const vector<vector<int>> &matrix, vector<int> &output, int col, int from, int end);

vector<int> spiralTraverse(vector<vector<int>> array)
{
	if (array.empty())
		return {};

	vector<int> spiralOrder;
	int row1 = 0;
	int row2 = (int)array.size()-1;
	int col1 = 0;
	int col2 = (int)array[0].size()-1;
	spiralOrder.reserve((row2+1)*(col2+1));

	while (true)
	{
		pushRow(array, spiralOrder, row1, col1, col2); ++row1; if (row1 > row2) break;
		pushCol(array, spiralOrder, col2, row1, row2); --col2; if (col1 > col2) break;
		pushRow(array, spiralOrder, row2, col2, col1); --row2; if (row1 > row2) break;
		pushCol(array, spiralOrder, col1, row2, row1); ++col1; if (col1 > col2) break;
	}
	return spiralOrder;
}

void pushRow(const vector<vector<int>> &matrix, vector<int> &output, int row, int from, int end)
{
	if (from <= end)
		for (int c = from; c <= end; ++c)
			output.push_back(matrix[row][c]);
	else
		for (int c = from; c >= end; --c)
			output.push_back(matrix[row][c]);		
}

void pushCol(const vector<vector<int>> &matrix, vector<int> &output, int col, int from, int end)
{
	if (from <= end)
		for (int r = from; r <= end; ++r)
			output.push_back(matrix[r][col]);
	else
		for (int r = from; r >= end; --r)
			output.push_back(matrix[r][col]);
}