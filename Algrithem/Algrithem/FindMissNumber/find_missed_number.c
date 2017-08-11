//
//  find_missed_number.c
//  Algrithem
//
//  Created by JasonLee on 2017/8/11.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#include "find_missed_number.h"

int find_missed_number_with_sum(int array[], int n)
{
    int sum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        sum += array[i];
    }
    
    return n * (n + 1) / 2 - sum;
}

int find_missed_number_with_binary_search(int array[], int n)
{
    return -1;
}

int *quick_sort(int array[])
{
    
    
    return array;
}

int find_missed_number_with_sorted(int array[], int n)
{
    
    return -1;
}
