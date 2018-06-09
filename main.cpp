/* C++ 11 required */
/* Coding = UTF-8 */
#include <iostream>
#include "skiplist.h"

#include <random>
#include <algorithm>
#include <chrono>
/*
 * skiplist的节点是node类。skiplist作为一个driver，其中存储包含了首个dummy node和尾部的dummy node。
 * 这两个dummy node中的key分别存储了INT_MIN与INT_MAX，作为sentinal
 * node类中用vector容器存储该节点各层的指向下一个节点的指针
 * 对于tester来说，需要调用skiplist的类，来测试方法：del, insert, find, 构造函数；可以使用print方法检查方法调用后的正确性
 * 并且tester还要测试时间性能
 * */


void insertTest(int N)
{
    std::default_random_engine e;
    //std::uniform_int_distribution<> u(INT_MIN, INT_MAX);
    std::uniform_int_distribution<> u(-50, 50);
    const int testNum = 10;
    double totalTime = 0;
    std::vector<int> init_vector(N);
    //generate random vector
    for (int j = 0; j < N; ++j) {
        init_vector[j] = u(e);//using random num to initialize vector
    }
    std::sort(init_vector.rbegin(), init_vector.rend());//descending order
    std::uniform_int_distribution<> v(*init_vector.cbegin(), *init_vector.cend());
    for (int i = 0; i < testNum; ++i) {
        SkipList::skiplist list(init_vector);//init skiplist
        auto start = std::chrono::system_clock::now();//start clock
        int temp_random = v(e);
        list.insert(init_vector[temp_random - temp_random / N * N]);
        auto end = std::chrono::system_clock::now();//clock ends
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        totalTime += double(duration.count()) * std::chrono::microseconds::period::num /
                     std::chrono::microseconds::period::den;
    }
    std::cout << totalTime << std::endl; //not divide testNum
}

int main()
{
    //BasicTest::test_randomGenerator(100);
    //BasicTest::test_init();
    //BasicTest::test_insert();
    //BasicTest::test_search();
    //BasicTest::test_del();
    //insertTest(20);
    insertTest(1);
    insertTest(10);
    insertTest(50);
    insertTest(100);
    insertTest(1000);
    //insertTest(2000);
    insertTest(3000);
    //insertTest(4000);
    insertTest(5000);
    //insertTest(6000);
    insertTest(7000);
    //insertTest(8000);
    //insertTest(9000);
    insertTest(10000);
    insertTest(12000);
    insertTest(15000);
    insertTest(17000);
    insertTest(20000);
    return 0;
}