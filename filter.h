#ifndef __FILTER_H__
#define __FILTER_H__

#include <vector>

/**
 * \brief 滤波器的接口
 * Filter是所有滤波器的基类，符合滤波器特性的类都必须继承自该类。
 */
template <typename T>
class Filter {
public:
    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并清空所有的寄存器。
     */
    virtual void init() = 0;
    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并可以指定寄存器的值。此函数使用了常量引用。
     * \param states 滤波器的当前状态
     */
    virtual void init(const std::vector<T> &states) = 0;
    /**
     * \brief 滤波器初始化
     * 此函数对滤波器进行初始化，并可以指定寄存器的值。此函数使用了右值引用。
     * \param states 滤波器的当前状态
     */
    virtual void init(std::vector<T> &&states) = 0;
    /**
     * \brief 滤波器执行
     * 此函数模拟滤波器一个周期的执行情况，包括输入和输出。
     * \param in 滤波器的当前输入
     * \return 滤波器的当前输出
     */
    virtual T cycle(T in) = 0;
    /**
     * \brief 获取滤波器阶数
     * 此函数获取滤波器的阶数。
     * \return 滤波器的阶数
     */
    virtual size_t getOrder() const = 0;
};

#endif
