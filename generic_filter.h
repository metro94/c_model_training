#ifndef __GENERIC_FILTER_H__
#define __GENERIC_FILTER_H__

#include "filter.h"

#include <vector>
#include <list>
#include <algorithm>

/**
 * \brief 通用滤波器
 * GenericFilter实现了一个简单的滤波器。
 */
template <typename T>
class GenericFilter : public Filter<T> {
public:
    /**
     * \brief 通用滤波器的构造函数
     * 此函数对通用滤波器设置了抽头系数。此函数使用了常量引用。
     * \param _taps 滤波器的抽头系数
     */
    GenericFilter(const std::vector<T> &_taps)
        : taps(_taps) {}
    /**
     * \brief 通用滤波器的构造函数
     * 此函数对通用滤波器设置了抽头系数。此函数使用了右值引用。
     * \param _taps 滤波器的抽头系数
     */
    GenericFilter(std::vector<T> &&_taps)
        : taps(_taps) {}

    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并清空所有的寄存器。
     */
    virtual void init();
    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并可以指定寄存器的值。此函数使用了常量引用。
     * \param states 滤波器的当前状态
     */
    virtual void init(const std::vector<T> &states);
    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并可以指定寄存器的值。此函数使用了右值引用。
     * \param states 滤波器的当前状态
     */
    virtual void init(std::vector<T> &&states);
    /**
     * \brief 滤波器执行
     * 此函数模拟滤波器一个周期的执行情况，包括输入和输出。
     * \param in 滤波器的当前输入
     * \return 滤波器的当前输出
     */
    virtual T cycle(T in);
    /**
     * \brief 获取滤波器阶数
     * 此函数获取滤波器的阶数。
     * \return 滤波器的阶数
     */
    virtual size_t getOrder() const { return regs.size(); }

private:
    std::vector<T> taps; ///< \brief 滤波器的抽头
    std::list<T> regs; ///< \brief 滤波器的寄存器
};

template <typename T>
void GenericFilter<T>::init()
{
    size_t len = taps.size();

    regs.resize(len); // 清空寄存器
}

template <typename T>
void GenericFilter<T>::init(const std::vector<T> &states)
{
    size_t len = taps.size();

    // 判断滤波器的阶数是否冲突
    if (states.size() != len)
        return;

    regs.resize(len); // 清空寄存器
    std::copy(states.cbegin(), states.cend(), regs.begin()); // 从外界复制寄存器的值
}

template <typename T>
void GenericFilter<T>::init(std::vector<T> &&states)
{
    size_t len = taps.size();

    // 判断滤波器的阶数是否冲突
    if (states.size() != len)
        return;

    regs.resize(len); // 清空寄存器
    std::copy(states.cbegin(), states.cend(), regs.begin()); // 从外界复制寄存器的值
}

template <typename T>
T GenericFilter<T>::cycle(T in)
{
    T result(0);
    auto tapIter = taps.cbegin(); // 指定第一个抽头的指针

    regs.emplace_front(in); // 压入最新的数据
    regs.pop_back(); // 弹出最老的数据

    for (auto reg : regs) // 遍历每个寄存器
        result += *tapIter++ * reg; // 求卷积

    return result;
}

#endif
