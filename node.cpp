#include "node.h"
namespace SkipList {
    //initiliaze the node by a vector containing nullptr
    node::node(int key, size_t levelNum)
    {
        this->key = key;
        auto levels = std::vector<node *>{levelNum, nullptr};
        this->levels = levels;
    }

    //constructor 2
    node::node(int X)
    {
        key = X;
        this->levels = std::vector<node *>{nullptr};
    }

    //constructor 3
    node::node(int key, std::vector<SkipList::node *> &levels)
    {
        this->key = key;
        this->levels = levels;
    }
}
