#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>

using namespace std;

class Alpha
{
public:
    static const int DEFAULT_NUM_LISTS = 5;

    Alpha()
    {
        for (int i = 0; i < DEFAULT_NUM_LISTS; i++) {
            vec.push_back({}); ///a vector of list *
        }
    }

    Alpha(const Alpha& src) = default;
    ~Alpha() = default;
    Alpha& operator=(const Alpha& rhs) = default;

    void populate(const int numValuesToGenerate = 75)
    {
        int delay = 0;
        for (int x = 0; x < numValuesToGenerate; x++) {
            delay++;
            if (delay == 3) {
                const int index = x % DEFAULT_NUM_LISTS;
                vec[index].push_back(x);
                delay = 0;
            }
        }
    }

    void display(std::ostream& outs = std::cout) const
    {
        for (const list<int>& aList : vec) {
            for (const int& value : aList) {
                outs << value << " ";
            }
            outs << endl;
        }
    }

private:
    vector<list<int>> vec;
};

int main ()
{
    Alpha alpha;

    alpha.populate();
    alpha.display();

    return 0;
}
