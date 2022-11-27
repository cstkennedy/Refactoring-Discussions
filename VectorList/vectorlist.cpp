///an unknown number of sub-collections
#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

std::pair<int, int> _process_arguments(const int argc, const char* const* argv)
{
	// Args: executable [0] [1]
	if (argc >= 3) {
		return {atoi(argv[1]), atoi(argv[2])};
	}

	int num_lists = -1;
	int num_ints = -1;
    cout << "How many lists? ";
    cin >> num_lists;
    cout << "How many integers? ";
    cin >> num_ints;

	return {num_lists, num_ints};
}

std::vector<std::list<int>> generate_integers(const int num_lists,
											  const int num_ints)
{
	vector<list<int>> vec(num_lists);
	// vec.resize(num_lists);

	for (int i = 0; i < num_ints; ++i) {
		const int idx = i % num_lists;
		vec[idx].push_back(i);
	}

	return vec;
}

std::ostream& operator<<(std::ostream& outs, const std::vector<std::list<int>>& vec)
{
	int idx = 0;
	for (const std::list<int>& a_list : vec) {
		outs<<"MyList #" << idx << "\n";
		++idx;

		for (const int& val : a_list) {
			outs << val << " ";
		}
		outs << "\n\n";
	}

	return outs;
}

int main(const int argc, const char* const* argv)
{
	const auto [num_lists, num_ints] = _process_arguments(argc, argv);
	auto vec = generate_integers(num_lists, num_ints);

	cout << vec;
	return 0;
}

