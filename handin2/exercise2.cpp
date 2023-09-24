template <typename Object>
void Matrix<Object>::transpose()
{
	int rows = numrows();
	int cols = numcols();

	// Ensure the matrix is non-empty before transposing
	if (rows == 0 || cols == 0)
	{
		return;
	}

	// Dimensions are equal, perform in-place transpose - no reallocation needed
	if (rows == cols)
	{
		for (int i = 0; i < cols; ++i)
		{
			for (int j = i + 1; j < rows; ++j)
			{

				std::swap(array[i][j], array[j][i]);
			}
		}
	}
	// Dimensions are not equal, reallocate and copy
	else
	{
		// Create a new matrix with swapped dimensions
		Matrix<Object> transposed(cols, rows);

		// Copy elements from the original matrix to the transposed matrix
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				transposed.array[j][i] = array[i][j];
			}
		}

		// Swap the original matrix with the transposed matrix
		*this = transposed;
	}
}
// The big o notation for the transpose function is O(n^2) because it has two nested for loops.s