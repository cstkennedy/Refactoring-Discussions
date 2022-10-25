// Binary Trees
// Author: JAY MORRIS
// Edited by: Thomas Kennedy

#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "BinaryTree.h"

using namespace std;


int main(int argc, char** argv)
{
    //--------------------------------------------------------------------------
    // Random Number Setup Lines
    //--------------------------------------------------------------------------
    default_random_engine* gptr = new default_random_engine(time(NULL));
    uniform_int_distribution<int> integerDistribution(0, 100);
    uniform_int_distribution<int> characterDistribution(65, 90);

    //--------------------------------------------------------------------------
    // User Input
    //--------------------------------------------------------------------------
    int numberToCreate = 0;
    cout << "Add how many AlphaNodes?" << endl;
    cin >> numberToCreate;

    /*
    for (int i = 0 ; i < numberToCreate; ++i) {
        char c = (char) characterDistribution(*gptr);
        cout << c << "\n";
    }
    */

    //--------------------------------------------------------------------------
    // Create a tree
    //--------------------------------------------------------------------------
    BinaryTree tree;

    for (int i = 0; i < numberToCreate; i++) {

        int v = integerDistribution(*gptr);
        char c = (char) characterDistribution(*gptr);

        cout << "Adding AlphaNode : (" << v << ", " << c << ")" << endl;
        tree.addNode(v, c);
    }

    cout << tree;

    return 0;

}

