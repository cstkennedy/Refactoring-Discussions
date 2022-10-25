// Binary Trees
// Author: JAY MORRIS

#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class alpha
{
public:
    alpha() { Left = NULL; Right = NULL; Mychild = NULL; ct = 0; }
    ~alpha() {}
    void setval(int v) { val = v; ct = 1; }
    void setlet(char c) { let = c; }
    int getval() { return val; }
    void display() {
        if (Left != NULL) { Left->display(); }
        cout << "alpha: " << val << " appeared " << ct << " times let = " << let << endl;
        if (Mychild != NULL) { Mychild->display(); }
        if (Right != NULL) { Right->display(); }
    }

    void addalpha(alpha* aptr)
    {
        if (val == aptr->getval()) {
            cout << val << " already exists" << endl; ct++;
            if (Mychild == NULL) { Mychild = aptr; }
            else { Mychild->addalpha(aptr); }
            aptr = NULL;
        }
        if (aptr->getval() < val) {
            if (Left == NULL) { Left = aptr; }
            else { Left->addalpha(aptr); }
        }
        else {
            if (Right == NULL) { Right = aptr; }
            else { Right->addalpha(aptr); }
        }
        aptr = NULL;
    }

private:
    int val;
    int ct;
    char let;
    alpha* Left;
    alpha* Right;
    alpha* Mychild;
};

int main(int argc, char** argv)
{
    default_random_engine* gptr;
    gptr = new default_random_engine(time(NULL));
    uniform_int_distribution<int> Idist(0, 100);
    uniform_int_distribution<int> Cdist(0, 25);

    alpha* root;
    alpha* curr;
    root = new alpha();
    root->setval(50);
    root->setlet('M');

    int n, v;
    char c;
    cout << "add how many alphas?" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        curr = new alpha;
        v = Idist(*gptr);
        c = 'A' + Cdist(*gptr);
        cout << "adding alpha : " << v << endl;
        curr->setval(v);
        curr->setlet(c);
        root->addalpha(curr);
    }

    root->display();

    return 0;

}

