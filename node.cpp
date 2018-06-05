//
// Created by cjw on 2018/6/4.
//

#include "node.h"
namespace SkipList {
    node::node(int key, size_t levelNum)
    {
        this->key = key;
        auto levels = std::vector<node *>{levelNum, nullptr};
        this->levels = levels;
    }

    node::node(int X)
    {
        key = X;
        this->levels = std::vector<node *>();
    }

    node::node(int key, std::vector<SkipList::node *> &levels)
    {
        this->key = key;
        this->levels = levels;
    }
}
