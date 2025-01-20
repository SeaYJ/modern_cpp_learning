#pragma once

#include <iostream>


/**********************\
* ���� long long ������ *
\**********************/

long long x = 65536LL;  // Yes
long long x = 65536;    // No
unsigned long long y = 65536ull;    // Yes
unsigned long long y = 65536;       // No

long long max_long_long = std::numeric_limits<long long>::max();    // long long max
long long min_long_long = std::numeric_limits<long long>::min();    // long long min


/********************************\
* ���ַ����� char16_t �� char32_t *
\********************************/

wchar_t ch = 'a';   // windows �����ַ����ͣ�����ƽ̨��������ʹ��

char8_t ch = u8'a'; // C++20 ���룬C++20 ֮ǰ������ʹ�� char ���� u8 �ַ�
char16_t ch = u'a'; // Сд u ǰ׺ -> 16 bit
char32_t ch = U'a'; // ��д U ǰ׺ -> 32 bit
