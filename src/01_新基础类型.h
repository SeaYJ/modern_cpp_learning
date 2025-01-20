#pragma once

#include <iostream>


/**********************\
* 关于 long long 的引入 *
\**********************/

long long x = 65536LL;  // Yes
long long x = 65536;    // No
unsigned long long y = 65536ull;    // Yes
unsigned long long y = 65536;       // No

long long max_long_long = std::numeric_limits<long long>::max();    // long long max
long long min_long_long = std::numeric_limits<long long>::min();    // long long min


/********************************\
* 新字符类型 char16_t 和 char32_t *
\********************************/

wchar_t ch = 'a';   // windows 常用字符类型，“跨平台”不建议使用

char8_t ch = u8'a'; // C++20 引入，C++20 之前可正常使用 char 接受 u8 字符
char16_t ch = u'a'; // 小写 u 前缀 -> 16 bit
char32_t ch = U'a'; // 大写 U 前缀 -> 32 bit
