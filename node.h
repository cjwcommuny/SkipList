#ifndef SKIPLISTCPPVERSION_NODE_H
#define SKIPLISTCPPVERSION_NODE_H

#include <vector>
#include "node.h"
namespace SkipList {
    class node
    {
    private:
        //int maxLevel;
    public:
        int key = 0;//存储用于大小比较的数值
        std::vector<node *> levels;//存储各层指向对应下一个节点的指针
        node() = default;
        explicit node(int X);
        node(int key, size_t levelNum);
        node(int key, std::vector<node *> &levels);//
        ~node() = default;//TODO
    };
}

#endif //SKIPLISTCPPVERSION_NODE_H
