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

// 该题简单比较简单，择时再补吧

int find_missed_number_with_binary_search(int array[], int n)
{
    // 快速排序，二分查找；
    
    return -1;
}

int *quick_sort(int array[])
{
    
    
    return array;
}

int find_missed_number_with_sorted(int array[], int n)
{
    // 创建对应大小的数组，按值对应的下标插入
    
    // 遍历数组内容，数字为空的就是对应缺少的
    
    // 时间复杂度为O(n)
    
    return -1;
}
