#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cassert>

using std::cout;
using std::cerr;
using std::endl;



struct BinaryTree {
    struct AlphaNode
    {
        AlphaNode()
            :AlphaNode(-1, '\0')
        {
            ct = 0;
        }

        AlphaNode(int val, char let)
        {
            left = nullptr;
            right = nullptr;
            myChild = nullptr;
            ct = 1;
            value = val;
            letter = let;
        }

        ~AlphaNode() = default;

        void incrementCount()
        {
            ++ct;
        }

        /**
         * @todo Replace with an iterative in-order traversal.
         */
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

        int value;
        int ct;
        char letter;
        AlphaNode* left;
        AlphaNode* right;
        AlphaNode* myChild;
    };

    AlphaNode* root;

    BinaryTree()
        :BinaryTree(50, 'M')
    {
    }

    BinaryTree(int value, char letter)
    {
        root = new AlphaNode(value, letter);
    }

    ~BinaryTree()
    {
        cerr << "~BinaryTree Not Yet Implemented\n";
    }

    /**
     * An iterative addNode method
     *
     * @todo expand documentation
     */
    void addNode(int valueToStore, char letterToStore)
    {
        AlphaNode* aPtr = new AlphaNode(valueToStore, letterToStore);
        AlphaNode* cursor = this->root;
        // We know aPtr-getValue == value

        while (cursor != nullptr) {
            if (cursor->value == valueToStore) {
                cerr << cursor->value << " already exists" << endl;
                cursor->incrementCount();

                if (cursor->myChild == nullptr) {
                    cursor->myChild = aPtr;
                }
                else {
                    // Handle the case where valueToStore = cursor->value
                    addCollisionNode(cursor->myChild, aPtr);
                }
                aPtr = nullptr;
                cursor = nullptr;
            }
            else if (valueToStore < cursor->value) {
                if (cursor->left == nullptr) {
                    cursor->left = aPtr;
                    cursor = nullptr;
                }
                else {
                    cursor = cursor->left;
                }
            }
            else if (valueToStore > cursor->value){
                if (cursor->right == nullptr) {
                    cursor->right = aPtr;
                    cursor = nullptr;
                }
                else {
                    cursor = cursor->right;
                }
            }
        }
    }

    void addCollisionNode(AlphaNode* startNode, AlphaNode* aPtr)
    {
        assert(aPtr != nullptr);
        assert(startNode->value == aPtr->value);

        AlphaNode* cursor = startNode;
        while (cursor->myChild != nullptr) {
            cerr << cursor->value << " already exists" << endl;
            cursor->ct++;
            cursor = cursor->myChild;
        }
        cursor->ct++;
        cursor->myChild = aPtr;
    }

};


std::ostream& operator<<(std::ostream& outs, const BinaryTree& toPrt)
{
   (toPrt.root)->display(outs);

   return outs;
}


#endif
