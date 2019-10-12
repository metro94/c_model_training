#ifndef __FILTER_TESTER_H__
#define __FILTER_TESTER_H__

#include "filter.h"

#include <iostream>
#include <vector>

/**
 * \brief 测试滤波器
 * 此函数对滤波器进行简单测试，接受输入seq并输出滤波后的结果。此函数的seq为常量引用。
 * 此函数将按照输入和输出的顺序输出每个周期的状态。
 * \param f 待测试的滤波器
 * \param seq 测试序列
 */
template <typename T>
void TestFilter(Filter<T> *f, const std::vector<T> &seq);

/**
 * \brief 测试滤波器
 * 此函数对滤波器进行简单测试，接受输入seq并输出滤波后的结果。此函数的seq为常量引用。
 * 此函数将按照输入和输出的顺序输出每个周期的状态。
 * \param f 待测试的滤波器
 * \param seq 测试序列
 */
template <typename T>
void TestFilter(Filter<T> *f, std::vector<T> &&seq);

template <typename T>
void TestFilter(Filter<T> *f, const std::vector<T> &seq)
{
    f->init(); // 初始化寄存器

    for (auto in : seq) {
        std::cout << "In: " << in;
        std::cout << ", Out: " << f->cycle(in) << std::endl;
    }
}

template <typename T>
void TestFilter(Filter<T> *f, std::vector<T> &&seq)
{
    f->init(); // 初始化寄存器
    
    for (auto in : seq) {
        std::cout << "In: " << in;
        std::cout << ", Out: " << f->cycle(in) << std::endl;
    }
}

#endif
