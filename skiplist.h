#ifndef SKIPLISTCPPVERSION_SKIPLIST_H
#define SKIPLISTCPPVERSION_SKIPLIST_H

#include "node.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include <random>
#include <algorithm>

namespace SkipList {
    class skiplist {
    private:
        node dummyNode;//首节点，存有INT_MIN，作为sentinal
        node *tailNode;//尾节点，存有INT_MAX，作为sentinal
        size_t nodeNum = 0;//skiplist的总节点数
        void del_recursive(node *delNode);
    public:
        explicit skiplist(const std::vector<int> &initVec);//由一个vector初始化skiplist，用于最初的skiplist初始化，特别注意要求这个vector降序！！
        ~skiplist();
        void insert(int X);//插入元素
        node *find(int X);//查找元素，如果没找到返回nullptr，找到的话返回指向对应node的指针
        bool del(int X);//删除元素，如果该元素存在在skiplist中，删除它并返回true，否则返回false
        size_t getMaxLevel();//读取当前skiplist的最大层数
        void print();//打印出skiplist，打印格式是(key值, 该node的层数) (key值, 该node的层数) (key值, 该node的层数) 
        static size_t determineLevelNum();//用于生成一个几何分布，用于决定某个节点有几层
    };
}


#endif //SKIPLISTCPPVERSION_SKIPLIST_H
