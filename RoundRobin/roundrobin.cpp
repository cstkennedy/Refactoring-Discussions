///an unknown number of sub-collections
#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <array>
#include <iterator>

using namespace std;


/**
 * T.B.W.
 */
template<class T, size_t N_ROWS, size_t N_COLS>
void print_matrix(const std::array<std::array<T, N_COLS>, N_ROWS>& matrix,
	 std::ostream& outs = std::cout)
{
	for(int row = 0; row < matrix.size(); row++) {
		for(int col = 0; col < matrix[row].size(); col++) {
			outs << matrix[row][col] << "  ";
		}
		outs << "\n";
	}
}

/**
 * T.B.W.
 */
template<class T, size_t N_ROWS, size_t N_COLS>
std::ostream& operator<<(std::ostream& outs,
						 const std::array<std::array<T, N_COLS>, N_ROWS>& matrix)
{
	print_matrix(matrix, outs);
	return outs;
}

/**
 * T.B.W.
 */
template <class T>
void shift_list_entries(std::list<T>& data)
{
	auto itr = data.begin();
	std::advance(itr, 2);

	data.push_back(*itr);
	data.erase(itr);

	itr = data.begin();
	std::advance(itr, 2);

	data.push_front(*itr);
	data.erase(itr);
}

/**
 * T.B.W.
 */
template<class T, size_t N_ROWS, size_t N_COLS>
void update_matrix(std::array<std::array<T, N_COLS>, N_ROWS>& matrix,
				   std::list<T>& data)
{
	for(int row = 0; row < matrix.size(); row++){
		for(int col = 0; col < matrix[row].size(); col++) {
			if((row != 0) || (col != 0)) {
				matrix[row][col] = data.front();
				data.push_back(data.front());
				data.pop_front();
			}
		}
	}
}

int main ()
{
	std::array<std::array<int, 4>, 2> matrix = {1};

	list<int> data {2, 3, 4, 8, 7, 6, 5};

	const int num_shift_iterations = 8;
	for(int i = 1; i < num_shift_iterations; i++)
	{
		update_matrix(matrix, data);
		cout << matrix << "\n\n";
		shift_list_entries(data);
    }
    return 0;
}
