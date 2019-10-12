#include <cstdio>
#include <vector>
#include "generic_filter.h"
#include "filter_tester.h"

using namespace std;

using DataType = int; // 定义使用的数据类型

int main()
{
    GenericFilter<DataType> f({ 1, 2, 3, 4 }); // 定义通用滤波器

    f.init({ -1, -2, -3, -4 }); // 初始化滤波器的状态
    TestFilter(&f, { 1, 2, 3, 4 }); // 测试滤波器
}
