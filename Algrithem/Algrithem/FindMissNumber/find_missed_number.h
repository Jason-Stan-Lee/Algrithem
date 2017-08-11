//
//  find_missed_number.h
//  Algrithem
//
//  Created by JasonLee on 2017/8/11.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#ifndef find_missed_number_h
#define find_missed_number_h

#include <stdio.h>

/*
 Question: Find missed number:
 
 Given an array which have n-1 items,the range of this items is [1, n], the array missed one of them.
 Write code to find the missed number.
 
 Function Definition
 
 int find_missed_number(
                        int array[],
                        int n)
 
 {
 
 }
 
 input:
 
  int array[] = {1, 2, 4};
  n = 4;
 
 output:
 
  3;
 */


// O(n)
int find_missed_number_with_sum(int array[], int n);

// O(nlog(n))
int find_missed_number_with_binary_search(int array[], int n);

// O(n)
int find_missed_number_with_sorted(int array[], int n);

#endif /* find_missed_number_h */
