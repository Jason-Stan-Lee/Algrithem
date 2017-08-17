//
//  number_of_digit_one.c
//  Algrithem
//
//  Created by JasonLee on 2017/8/17.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#include "number_of_digit_one.h"
#include <math.h>
#include <stdlib.h>

// 解题思路见图纸

// 获取当前数字位数的最大整数
// eg: input: a number between 100 and 199, output:999
int max_num_of_same_digit(unsigned long n);
int max_num_of_same_digit_ex(int ex);

// 获取数字最大位数上的数字
int get_max_digit_number(long number);
int get_max_digit_number_ex(long number, int ex);

// 获取数字的位数
int get_digits(long number);

long count_of_digit_one_recursion(long n)
{
    long number = labs(n);
    
    if (0 == number) return 0;
    
    // 比number小一位的位数
    int ex = get_digits(number / 10);
    // number最大位数字
    int co = get_max_digit_number_ex(number, ex + 1);
    // number的单位数字，用来区分最大位数是否达到1
    int unit_num = pow(10, ex);

    long sum = 0;
    
    // number最大位数为1
    if (number >= unit_num && number < 2 * unit_num)
        sum = number - unit_num + 1;
    
    // number最大位数比1大
    if (number >= 2 * unit_num)
        sum = unit_num;
    
    // number减去（最大位数 x unit_num）的部分求1的个数
    long last = 0;
    
    if (number > 10)
        last = count_of_digit_one_recursion(number - co * unit_num);
    
    int max_subnum = max_num_of_same_digit_ex(ex);
    // 此部分可以用循环来做，可以提高效率
    long sub_digit_count_of_one = count_of_digit_one_recursion(max_subnum);
    
    return sub_digit_count_of_one * co + sum + last;
}

long count_of_digit_one_circulation(long n) {
    
    long number = labs(n);

    if (0 == number) return 0;
    
    int ex = get_digits(number / 10);
    int co = get_max_digit_number_ex(number, ex + 1);
    int unit_num = pow(10, ex);
    
    long sum = 0;
    
    if (number >= unit_num && number < 2 * unit_num)
        sum = number - unit_num + 1;
    
    if (number >= 2 * unit_num)
        sum = unit_num;
    
    long last = 0;
    
    if (number > 10)
        last = count_of_digit_one_recursion(number - co * unit_num);
    
    long sub_digit_count_of_one = 0;
    int temp = ex + 1;
    
    while (temp > 0) {
        
        sub_digit_count_of_one = sub_digit_count_of_one * 10 + pow(10, (ex - temp));
        temp--;
    }
    
    return sub_digit_count_of_one * co + sum + last;
}

int max_num_of_same_digit(unsigned long n) {
    
    int ex = get_digits(n);
    
    return get_max_digit_number_ex(n, ex);
}

int max_num_of_same_digit_ex(int ex) {
    
    unsigned int ret = 0; // 输出结果
    
    for (int i = 0; i < ex; i++) {
        
        ret += pow(10, i) * 9;
    }
    
    return ret;
}

int get_max_digit_number(long number) {
    
    int ex = get_digits(number);
    
    return get_max_digit_number_ex(number, ex);
}

int get_max_digit_number_ex(long number, int ex) {
    
    if (0 == number) return 0;
    if (ex < 1) return 0;
    
    long temp = labs(number);
    
    return temp / pow(10, ex - 1);
}

int get_digits(long number) {
    
    if (number == 0) return 0;
    
    int digits = 0;
    long temp = labs(number);
    
    while(temp > 0) {
        temp = temp / 10;
        digits++;
    }
    
    return digits;
}


int count_of_digit_one_best(int n) {
    
    if (n < 0) return 0;
    
    int base = 1;
    int result = 0;
    
    while (n / base > 0) {
        
        int cur = n / base % 10;
        
        if (cur > 1) {
            result +=  (n/base/10 + 1) * base;
        } else if (cur == 1) {
            result += (n/base/10)*base + n%base + 1;
        } else {
            result += (n/base/10)*base;
        }
        
        if(base==1000000000) break;
        
        base *= 10;
    }
    
    return result;
}
