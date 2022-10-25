#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cassert>

using std::cout;
using std::cerr;
using std::endl;

class AlphaNode
{
public:
    AlphaNode()
    {
        left = nullptr;
        right = nullptr;
        myChild = nullptr;
        ct = 0;
    }

    ~AlphaNode() = default;

    void setValue(int v)
    {
        value = v;
        ct = 1;
    }

    void setLetter(char c)
    {
        letter = c;
    }

    int getValue()
    {
        return value;
    }

    int getLetter() const
    {
        return letter;
    }

    void display(std::ostream& outs = cout) const
    {
        if (left != nullptr) {
            left->display(outs);
        }

        outs << "AlphaNode: " << value << " appeared " << ct << " times"
             << " letter = " << letter << endl;

        if (myChild != nullptr) {
            myChild->display(outs);
        }

        if (right != nullptr) {
            right->display(outs);
        }
    }

    void addAlphaNode(AlphaNode* aPtr)
    {
        assert(aPtr != nullptr);

        if (this->value == aPtr->getValue()) {
            cerr << value << " already exists" << endl; ct++;
            if (myChild == nullptr) {
                myChild = aPtr;
            }
            else {
                myChild->addAlphaNode(aPtr);
            }
            aPtr = nullptr;
        }
        else if (aPtr->getValue() < value) {
            if (left == nullptr) {
                left = aPtr;
            }
            else {
                left->addAlphaNode(aPtr);
            }
            aPtr = nullptr;
        }
        else {
            if (right == nullptr) {
                right = aPtr;
            }
            else {
                right->addAlphaNode(aPtr);
            }
            aPtr = nullptr;
        }
    }

private:
    int value;
    int ct;
    char letter;
    AlphaNode* left;
    AlphaNode* right;
    AlphaNode* myChild;
};

// std::ostream& operator<<(std::ostream& outs, const AlphaNode& toPrt)
// {
    // toPrt.display(outs);

    // return outs;
// }
//
struct BinaryTree {
    AlphaNode* root;

    BinaryTree()
        :BinaryTree(50, 'M')
    {
    }

    BinaryTree(int value, char letter)
    {
        root = new AlphaNode();
        root->setValue(value);
        root->setLetter(letter);
    }

    ~BinaryTree()
    {
        cerr << "~BinaryTree Not Yet Implemented\n";
    }

    void addNode(AlphaNode* toAdd)
    {
        root->addAlphaNode(toAdd);
    }

    void addNode(int value, char letter)
    {
        AlphaNode* node = new AlphaNode();

        node->setValue(value);
        node->setLetter(letter);

        addNode(node);
    }
};


std::ostream& operator<<(std::ostream& outs, const BinaryTree& toPrt)
{
   (toPrt.root)->display(outs);

   return outs;
}


#endif
