//
//  number_of_digit_one.h
//  Algrithem
//
//  Created by JasonLee on 2017/8/17.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//  My answer of leet code 233.

#ifndef number_of_digit_one_h
#define number_of_digit_one_h

#include <stdio.h>

/*
 Leet Code 233:
 
 Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 
 For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

// circulation method to solve this problem
long count_of_digit_one_circulation(long number);

// recursion method to solve this problem
long count_of_digit_one_recursion(long number);

// the better method in leetcode
int count_of_digit_one_best(int number);

#endif /* number_of_digit_one_h */
