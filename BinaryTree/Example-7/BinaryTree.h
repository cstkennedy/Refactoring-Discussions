#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

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

        void incrementCount()
        {
            ++ct;
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
        for (const AlphaNode* cursor : inOrderTraversalHelper()) {

            AlphaNode* collisionCursor = cursor->myChild;
            while (collisionCursor != nullptr) {
                AlphaNode* toDel = collisionCursor;
                collisionCursor = collisionCursor->myChild;

                delete toDel;
            }

            delete cursor;
        }
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

    std::vector<AlphaNode*> inOrderTraversalHelper() const
    {
        std::vector<AlphaNode*> nodes;

        std::stack<AlphaNode*> traversalStack;
        AlphaNode* cursor = this->root;

        // loop until cursor == nullptr and stack is empty
        while (cursor != nullptr || !traversalStack.empty()) {
            while (cursor != nullptr) {
                traversalStack.push(cursor);
                cursor = cursor->left;
            }

            cursor = traversalStack.top();
            traversalStack.pop();

            nodes.push_back(cursor);

            cursor = cursor->right;
        }

        return nodes;
    }

    void display(std::ostream& outs) const
    {
        for (const AlphaNode* cursor : inOrderTraversalHelper()) {
            outs << "AlphaNode: " << cursor->value
                 << " appeared "  << cursor->ct << " times"
                 << " letter = "  << cursor->letter
                 << '\n';

            AlphaNode* collisionCursor = cursor->myChild;
            while (collisionCursor != nullptr) {
                outs << "AlphaNode: " << collisionCursor->value
                     << " appeared "  << collisionCursor->ct << " times"
                     << " letter = "  << collisionCursor->letter
                     << '\n';

                collisionCursor = collisionCursor->myChild;
            }
        }
    }
};


std::ostream& operator<<(std::ostream& outs, const BinaryTree& toPrt)
{
   toPrt.display(outs);

   return outs;
}


#endif
