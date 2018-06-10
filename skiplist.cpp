#include "skiplist.h"
namespace SkipList {
    /*
    * genenrate binomial distribution B(1,p) where p = 0.5
    * the meaning of this method is to help to generate geometric distribution
    * we use C++ 11 standard library to generate random value
    * */
    bool GenerateRandom()
    {
        std::random_device device;
        std::mt19937 gen(device());
        std::bernoulli_distribution b(0.5);
        bool result = b(device);
        return result;
    }

    /*
    * use this constructor to initialize the skiplist with a descending vector which
    * contains the correspoding keys
    * we construct skiplist from tail to head, using a dummy node stored in the class
    * skiplist to store the temporary information of pointer to the next node of every 
    * level
    */
    skiplist::skiplist(const std::vector<int> &initVec): dummyNode(INT_MIN)//initVec is a descending vector,tested
    {
        nodeNum = initVec.size();
        /*
        * tailNode serve as a sentinal which stores INT_MAX
        * so it's vector is no use, we don't have to 
        * allocate space for it.
        */
        tailNode = new node(INT_MAX);//another dummy node; no need for extra vector space
        /*
        * dummyNode is the head node of skiplist which contains INT_MIN 
        * serving as a sentinal too. in the process of initialization of skiplist, 
        * we use dummyNode's member "levels" to store the pointers which point to 
        * the next node of every level of the current node we are handling 
        */
        dummyNode.levels[0] = tailNode;//level 1

        //for every element of the vector, C++ 11 feature
        for (auto element: initVec) {
            //obtain the level of this node by random principle
            size_t levelNum = determineLevelNum();
            //newNode is the node we need to insert gradually
            auto newNode = new node(element, levelNum);
            /* if the level of this newNode is less than the total number of 
            * the skiplist, we need to append cell of vector in the dummy head
            * node.
            */
            if (levelNum > dummyNode.levels.size()) {
                /*
                * when the index of level of current node not out of the range of 
                * the number of levels of skiplist, we can just use the index to 
                * modify the vector
                * */
                for (auto i = 0; i < dummyNode.levels.size(); ++i) {
                    newNode->levels[i] = dummyNode.levels[i];
                    dummyNode.levels[i] = newNode;
                }
                /* 
                * the index of level of current node out of the range of 
                * the number of levels of skiplist, in this case we need use 
                * push_back() method to append cell of dummy node.
                */
                for (auto i = dummyNode.levels.size(); i < levelNum; ++i) {//range out of levels of dummy node
                    newNode->levels[i] = tailNode;
                    dummyNode.levels.push_back(newNode);
                }
            } else {
                /*
                * if the number of level of this node is less than the total
                * number of level of the skiplist, we don't have to append cell 
                * to the dummy head node, so it's the easy case
                * */
                for (auto i = 0; i < levelNum; ++i) {
                    newNode->levels[i] = dummyNode.levels[i];
                    dummyNode.levels[i] = newNode;
                }
            }
        }
    }

    /*
    * we can call "find" method to search an element in the skiplist
    * if an element is found, the method will return a pointer pointing 
    * to the node which contains this element. If not found, the method 
    * will return nullptr.
    */
    node* skiplist::find(int X)//completed
    {
        auto currentLevel = (int) getMaxLevel() - 1;
        node *currentNode = &dummyNode;
        /*
        * using a binary search from top level to the lower level
        */
        while (currentLevel >= 0) {
            //find the first node whose element is larger or equal than X
            while (currentNode->levels[currentLevel]->key < X) {
                currentNode = currentNode->levels[currentLevel];
            }
            //if the node we found is equal to X, then we find it
            if (currentNode->levels[currentLevel]->key == X) {//element found
                return currentNode->levels[currentLevel];
            } else {
                /*
                * if the node we found is not equal to X (namely larger than X),
                * we search the lower level
                */
                --currentLevel;
            }
        }
        //element not found, return nullptr
        return nullptr;
    }

    size_t skiplist::getMaxLevel()
    {
        //the max level of skiplist is equal to the max level of dummy head node 
        return dummyNode.levels.size();
    }

    /*
    * we use "del" method to delete an element in the skiplist
    * if the element is not found, we just do nothing and reuturn false,
    * else we delete the node of this element and reorganize the skiplist,
    * return true
    */
    bool skiplist::del(int X)
    {
        //index starts from 0
        int currentLevel = (int) getMaxLevel() - 1;
        node *currentNode = &dummyNode;
        node *nodeNeedDeleted = nullptr;
        /*
        * a serach analogous to the process in "find" method, 
        * the only difference is that we don't cease the process 
        * in the middle of our search, instead we continue this search
        * until all the necessary nodes have been search entirely
        */ 
        while (currentLevel >= 0) {
            while (currentNode->levels[currentLevel]->key < X) {
                currentNode = currentNode->levels[currentLevel];
            }
            if (currentNode->levels[currentLevel]->key == X) {
                //the node we want to delete is found
                nodeNeedDeleted = currentNode->levels[currentLevel];
                currentNode->levels[currentLevel] = nodeNeedDeleted->levels[currentLevel];
            }
            --currentLevel;
        }
        if (nodeNeedDeleted == nullptr) {
            //in the whole process, the node we want to delete has not been found
            return false;
        } else {
            //node has been found, just delete it
            --nodeNum;
            delete nodeNeedDeleted;
            return true;
        }
    }

    /*
    * we use "insert" method to insert an element into the skiplist.
    */
    void skiplist::insert(int X)
    {
        size_t levelNum = determineLevelNum();
        auto newNode = new node(X, levelNum);
        /*
        * we first have to determine whether the number of level of the node 
        * needed to be inserted is larger than the number of level of the skiplist.
        * if the answer is yes, we have to use "push_back" method to append cells in 
        * the dummy head node 
        */
        if (levelNum > getMaxLevel()) {
            size_t moreLevelNum = levelNum - getMaxLevel();
            for (int i = 0; i < moreLevelNum; ++i) {
                newNode->levels.push_back(tailNode);
                dummyNode.levels.push_back(newNode);
            }
        }
        node *currentNode = &dummyNode;
        int currentLevel = (int) levelNum - 1;//index start from 0
        /*
        * the analogous searching to find the position where node can be inserted.
        * in this search, we start from the max level of the node needed to be inserted
        * instead of the maximum level of the skiplist
        */
        while (currentLevel >= 0) {
            while (currentNode->levels[currentLevel]->key < X) {
                currentNode = currentNode->levels[currentLevel];
            }
            newNode->levels[currentLevel] = currentNode->levels[currentLevel];
            currentNode->levels[currentLevel] = newNode;
            --currentLevel;
        }
        ++nodeNum;
    }

    /*
    * we use "print" method to visualize the skiplist
    * the method will output the element and the number of level of 
    * each node in the standard output stream std::cout
    * the output format is like:
    * (key1, levelNum1) (key2, levelNum2) (key3, levelNum3) 
    * */
    void skiplist::print()
    {
        auto currentNode = dummyNode.levels[0];
        for (int i = 0; i < nodeNum; ++i) {
            std::cout << "("<< currentNode->key << "," << currentNode->levels.size() << ")"<< " ";
            currentNode = currentNode->levels[0];
        }
        std::cout << std::endl;
    }

    /*
    * we use this method to determine the numebr of level of a specific node
    * the method use geometrical distribution
    */
    size_t skiplist::determineLevelNum()//has been tested
    {
        size_t levelNum = 1;
        //GenerateRandom is a method to generate binomial distribution B(1, 0.5)
        while (GenerateRandom()) {
            ++levelNum;
        }
        return levelNum;
    }

    /*
     * delete the skiplist by recursive method del_recursive(...)
     */
    skiplist::~skiplist()
    {
        if (dummyNode.levels[0] == nullptr) {
            return;
        } else {
            del_recursive(dummyNode.levels[0]);
        }
    }

    /*
     * we use this method to recursively delete the node from tail
     * to head.
     */
    void skiplist::del_recursive(SkipList::node *delNode)
    {
        if (delNode->levels[0] == nullptr) {
            //if delNode is the tail node
            delete delNode;
        } else {
            del_recursive(delNode->levels[0]);
            delete delNode;
        }
    }
}