// Binary Trees
// Author: JAY MORRIS
// Edited by: Thomas Kennedy

#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <ctime>
#include <fstream>

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
    BinaryTree testTree;

    for (int i = 0; i < numberToCreate; i++) {

        int v = integerDistribution(*gptr);
        char c = (char) characterDistribution(*gptr);

        cout << "Adding AlphaNode : (" << v << ", " << c << ")" << endl;
        tree.addNode(v, c);

        testTree.addNodeIterative(v, c);
    }

    /*
    ostringstream outs1;
    ostringstream outs2;

    outs1 << tree;
    outs2 << testTree;

    if (outs1.str() == outs2.str()) {
        cout << string(20, '*') << "\n";
        cout << "Success!!!!\n";
        cout << string(20, '*') << "\n";
    }
    */

    ofstream outs1("tree1.txt");
    ofstream outs2("tree2.txt");

    outs1 << tree;
    outs2 << testTree;

    outs1.close();
    outs2.close();



    return 0;

}

