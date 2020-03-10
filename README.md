# README

| 项目     | 内容                                                         |
| -------- | ------------------------------------------------------------ |
| 课程链接 | [2020春季计算机学院软件工程(罗杰 任健)](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ) |
| 作业要求 | [个人项目作业](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10429) |
| 教学班级 | 006                                                          |
| 项目地址 | https://github.com/17373432/Project1                         |
| 博客链接 | https://www.cnblogs.com/cc17373432/p/12456682.html           |

## 作业要求概览

给定 N 个几何对象，询问平面中有多少个点在**至少 2 个**给定的几何对象上。**题目输入保证答案只有有限个。**

需要支持的几何对象为：直线，圆。

##### 输入格式

- 第 1 行：一个自然数 N >= 1，表示输入的几何对象的数目。**注**：具体的 N 的限制参见评分规则。
- 第 2 行至第 N + 1 行：每行描述一个几何对象。具体格式如下：
  - 直线：`L    `，表示通过点 (x1, y1) 和 (x2, y2) 的直线。输入保证给定两点不重合。
  - 圆：`C   `，表示以点 (x, y) 为中心，半径为 r 的圆。输入保证半径 r > 0。

所有几何对象参数均为整数，范围为 (-100000, 100000)。

## 项目结构

```
IntersectProject/ 
├── bin  # 可执行文件所在目录
│   └── intersect.exe # vs2019编译Release版exe
├── README.md
├── src	 # 项目源代码
│   ├── Project1.h #
│   ├── Proc.cpp # 主函数
│   ├── Circle.cpp # 圆类的方法实现
|   ├── Line.cpp # 直线类的方法实现
│   └── Point.cpp # 点类的方法实现
├── test  # vs2019单元测试相关代码
│   ├── pch.h 
│   ├── pch.cpp 
│   ├── test.cpp
└── └── *.txt # 博客中性能测试使用数据
```

## 如何运行

#### 程序运行：

运行`bin/intersect.exe`时，传入参数规定如下：

| **参数**                   | **参数意义**                                     | **用法示例**                               | 是否为必要参数 |
| -------------------------- | ------------------------------------------------ | ------------------------------------------ | -------------- |
| `-i <path to input file>`  | 带一个参数，表示输入文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` | 是             |
| `-o <path to output file>` | 带一个参数，表示输出文件的路径（绝对或相对路径） | `intersect.exe -i input.txt -o output.txt` | 是             |

举例：

```
bin/intersect.exe -i test/test1.txt -o out1.txt
```

运行环境：

- windows