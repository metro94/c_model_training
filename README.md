# C Model训练

本项目提供了一个C Model的基本模板，可供大家学习和参考。

## 编译

要编译该项目，只需执行`make`即可。默认生成的文件名为`filter`，可以在终端直接执行。
如果要清空生成的临时文件，可以执行`make clean`。

## 文档生成

该项目支持使用Doxygen生成文档。只需安装Doxygen，并在当前目录下运行`make doc`或`doxygen`即可。

## 项目结构

本项目包括以下几个文件：

* `filter.h`: 滤波器的接口或基类
* `generic_filter.h/.cpp`: 一个简单的通用滤波器
* `filter_tester.h/.cpp`: 一个简单的滤波器测试函数
* `main.cpp`: 主函数
