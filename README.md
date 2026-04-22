# Problem 110 - 小恶魔的生日

**ACMOJ Problem ID**: 1073

## Table of Contents

- [Problem 110 - 小恶魔的生日](#problem-110-小恶魔的生日)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1073. 小恶魔的生日** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/110/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

小恶魔助教的生日要到了，所以她发现可以让大家写个日期类纪念一下~

于是她想让大家写个Date（可惜这不代表你能拥有一个Date :(

你需要完成以下内容：

- `Date d;` 无参数即构造一个日期为1900年1月1日的日期。
  `Date d(yy, mm, dd)` 构造一个yy年mm月dd日的日期。**请注意检查该日期是否存在**，若不存在则默认构造一个日期为1900年1月1日的日期。
- 前置++/--, 后置++/--，其中`++d`/`d++`表示d变为后一天，对应的，`--d`/`d--`表示d变为前一天。
- 日期d+整数days，日期d-整数days。两个操作均返回一个日期。`+`为给定日期的后days天，`-`为给定日期的前days天。
- < 比较符。`d1 < d2` 若真返回1，若假返回0。注意比较方法按照年-月-日的顺序进行。例如，"2018年12月3日<2019年11月1日" 为真。
- 日期-日期：给定两个日期d1, d2, (d1-d2)表示二者之间间隔的天数。例如，2019年12月3日与2019年12月1日间隔2天，以此类推。请注意所有输出为正整数，即取绝对值。
- 输出日期。输出格式为 `_year-_month-_day` . 中间以'-'相连。例如，2019年12月3日输出为 "2019-12-3"(不含双引号，不需要补0)。请注意，此操作请使用重载输出运算符。但若无法实现，**为保证其他操作的测试顺利进行，也请你写一个`out()`函数来进行输出**（主程序部分可以采用注释里的写法）。此操作不会单独进行测试，但如果检查代码时发现你未重载输出运算符，你的所有得分将*0.8(例如你测试结果为60，未重载输出运算符会使你的得分变为48).
- **此题需要你注意提交代码的代码风格！！！极为糟糕的代码风格（例如改变语法的某些宏定义）会酌情扣分！！！**
- 你**只可以**在输出方式的选择上修改给定部分的代码，其余更改给定部分代码的需求请在考场上提问，否则后果自负。

### Input Format

第一行一个$op$表示操作号。
其余输入具体见给定代码的主程序部分。

### Output Format

输出方式详见主程序。
你的out函数中需要进行换行。

### Samples

#### Sample 1

**Input:**
```
0
1926 8 17
1999 12 21
2021 1 1
1926 8 17
```

**Output:**
```
1900-1-1
2000-2-29
1900-1-1
1926-8-18
1926-8-19
1926-8-20
1926-8-21
1926-8-22
1926-8-22
1926-8-23
1926-8-24
1926-8-25
1926-8-26
1926-8-27
1926-8-26
1926-8-25
1926-8-24
1926-8-23
1926-8-21
1926-8-20
1926-8-20
2000-3-30
1997-3-26
0
5168
```

### Data Constraints

保证测试日期在1900年1月1日到2030年12月31日之间。

测试点编号 | op|  测试点分值
-|-|-|
1 | 1 | 10
2 | 2 | 20
3 | 3 | 20
4 | 4 | 10
5 | 5 | 20
6 | 0 | 20

`sample.cpp`如下

```C++
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
    //构造函数
	//判断是否为闰年
	//一个日期加上一个天数
	//一个日期减去一个天数
	//前置++
	//后置++
	//前置--
	//后置--
	//<重载
	//重载输出运算符
    //以上仅为提示，不代表你需要完成所有，你也可以添加其他需要的函数。
};

void Test()
{
    int op;
    cin >> op;
    int yy, mm, dd;
    if (op == 1 || op == 0)
    {
        Date d0;
        Date d1(2000, 2, 29);
        Date d2(1900, 2, 29);
        cout << d0 << endl;
        cout << d1 << endl;
        cout << d2 << endl;
        //d0.out(); d1.out(); d2.out();
    }
    if (op == 2 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        for (int i=0;i<5;++i) cout << ++d0 << endl; //(++d0).out();
        for (int i=0;i<5;++i) cout << d0++ << endl; //(d0++).out();
        for (int i=0;i<5;++i) cout << d0-- << endl; //(d0--).out();
        for (int i=0;i<2;++i) cout << --d0 << endl; //(--d0).out();
        cout << d0 << endl;
        //d0.out();
    }
    if (op == 3 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        cout << d0 + 100 << endl;
        // (d0+100).out();
        cout << d0 - 1000 << endl;
        // (d0-1000).out();
    }
    if (op == 4 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(2020, 12, 21);
        cout << (d0 < d1) << endl;
    }
    if (op == 5 || op == 0)
    {
        cin >> yy >> mm >> dd;
        Date d0(yy, mm, dd);
        Date d1(1912, 6, 23);
        cout << d0 - d1 << endl;
    }
}
int main()
{
	Test();
	return 0;
}
```

## Resource Limits

- **Time Limit**: 1000 ms
- **Memory Limit**: 64 MiB

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 64 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/110/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
