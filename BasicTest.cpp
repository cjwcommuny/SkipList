#include <vector>
#include "skiplist.h"
/*
 * This file is used by the programmer for the basic test of the correctness of the program
*/

namespace BasicTest {
    void test_init() {
        std::vector<int> sample1{8,7,6,5,4,3,2,1};
        std::vector<int> sample2{8,7,5,5,4,3,3,1};
        std::vector<int> sample3{132, 111, 111, 100, 100, 100, -1 ,-1, -5, -6};
        SkipList::skiplist skiplist1(sample1);
        SkipList::skiplist skiplist2(sample2);
        SkipList::skiplist skiplist3(sample3);
        skiplist1.print();
        skiplist2.print();
        skiplist3.print();
    }

    void test_randomGenerator(int N)
    {
        for (int i = 0; i < N; ++i) {
            std::cout << SkipList::skiplist::determineLevelNum() << " ";
        }
    }

    void test_insert()
    {
        std::vector<int> sample1{8,7,6,5,4,3,2,1};
        std::vector<int> sample2{8,7,5,5,4,3,3,1};
        std::vector<int> sample3{132, 111, 111, 100, 100, 100, -1 ,-1, -5, -6};
        SkipList::skiplist skiplist1(sample1);
        SkipList::skiplist skiplist2(sample2);
        SkipList::skiplist skiplist3(sample3);

        skiplist1.print();
        skiplist1.insert(1);
        skiplist1.print();
        skiplist1.insert(5);
        skiplist1.print();
        skiplist1.insert(6);
        skiplist1.print();
        skiplist1.insert(10);
        skiplist1.print();
        std::cout << std::endl;

        skiplist2.print();
        skiplist2.insert(5);
        skiplist2.print();
        skiplist2.insert(10);
        skiplist2.print();
        skiplist2.insert(6);
        skiplist2.print();
        skiplist2.insert(-1);
        skiplist2.print();
        std::cout << std::endl;

        skiplist3.print();
        skiplist3.insert(143);
        skiplist3.print();
        skiplist3.insert(-23);
        skiplist3.print();
        skiplist3.insert(100);
        skiplist3.print();
        skiplist3.insert(110);
        skiplist3.print();
        std::cout << std::endl;
    }
    void test_search()
    {
        std::vector<int> sample1{8,7,6,5,4,3,2,1};
        std::vector<int> sample2{8,7,5,5,4,3,3,1};
        std::vector<int> sample3{132, 111, 111, 100, 100, 100, -1 ,-1, -5, -6};
        SkipList::skiplist skiplist1(sample1);
        SkipList::skiplist skiplist2(sample2);
        SkipList::skiplist skiplist3(sample3);

        skiplist1.print();
        SkipList::node *node;
        if ((node = skiplist1.find(1)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist1.find(5)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist1.find(10)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist1.find(-1)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist1.find(8)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        std::cout << std::endl;

        skiplist2.print();
        if ((node = skiplist2.find(1)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist2.find(8)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist2.find(10)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist2.find(-1)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist2.find(3)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        std::cout << std::endl;

        skiplist3.print();
        if ((node = skiplist3.find(-6)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist3.find(15)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist3.find(111)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist3.find(-23)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        if ((node = skiplist3.find(132)) != nullptr) {
            std::cout << node->key << " ";
        } else {
            std::cout << "none" << " ";
        }
        std::cout << std::endl;
    }

    void test_del()
    {
        std::vector<int> sample1{8,7,6,5,4,3,2,1};
        std::vector<int> sample2{8,7,5,5,4,3,3,1};
        std::vector<int> sample3{132, 111, 111, 100, 100, 100, -1 ,-1, -5, -6};
        SkipList::skiplist skiplist1(sample1);
        SkipList::skiplist skiplist2(sample2);
        SkipList::skiplist skiplist3(sample3);

        skiplist1.print();
        std::cout << skiplist1.del(1) << std::endl;
        skiplist1.print();
        std::cout << skiplist1.del(5) << std::endl;
        skiplist1.print();
        std::cout << skiplist1.del(8) << std::endl;
        skiplist1.print();
        std::cout << skiplist1.del(10) << std::endl;
        skiplist1.print();
        std::cout << std::endl;

        skiplist2.print();
        std::cout << skiplist2.del(5) << std::endl;
        skiplist2.print();
        std::cout << skiplist2.del(10) << std::endl;
        skiplist2.print();
        std::cout << skiplist2.del(6) << std::endl;
        skiplist2.print();
        std::cout << skiplist2.del(8) << std::endl;
        skiplist2.print();
        std::cout << std::endl;

        skiplist3.print();
        std::cout << skiplist3.del(-6) << std::endl;
        skiplist3.print();
        std::cout << skiplist3.del(-23) << std::endl;
        skiplist3.print();
        std::cout << skiplist3.del(100) << std::endl;
        skiplist3.print();
        std::cout << skiplist3.del(132) << std::endl;
        skiplist3.print();
        std::cout << std::endl;
    }
}

