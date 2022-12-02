#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <memory>

struct Alpha
{
    int x;

	Alpha()
	  :Alpha(0)
	{
	}

	Alpha(int val)
	{
		this->x = val;
	}
};

bool operator< (const Alpha& lhs, const Alpha& rhs)
{
	return lhs.x < rhs.x;
}

bool operator< (const std::shared_ptr<Alpha>& lhs, const std::shared_ptr<Alpha>& rhs) {
	return *lhs < *rhs;
}

/*
auto create_pqueue()
{
	std::deque<std::shared_ptr<Alpha>> deq;
	auto compFunc = [](const auto lhs, const auto rhs) {
		return *lhs < *rhs;
	};

	std::priority_queue mypq(compFunc, deq);

	return mypq;
}
*/

int main ()
{
	// auto mypq = create_pqueue();
	std::priority_queue<std::shared_ptr<Alpha>> mypq;

	auto vals_to_add = {100, 10, 20, 52, 30, 84, 0, 40};
	for (int v : vals_to_add) {
		auto aptr = std::make_shared<Alpha>(v);
		mypq.push(aptr);
	}

	while (!mypq.empty()) {
		// std::shared_ptr<Alpha> x = mypq.top();
		auto x = mypq.top();
		mypq.pop();
		std::cout << "mypq.top() is now " << mypq.top()->x << '\n';
		std::cout<<" x = "<<x->x<<std::endl;
	}

	return 0;
}

