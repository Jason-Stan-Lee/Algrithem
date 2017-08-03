//
//  number_of_tasks_running_avl2.h
//  Algrithem
//
//  Created by JasonLee on 2017/8/3.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//  Use sorted datas array to make avl tree

#ifndef number_of_tasks_running_avl2_h
#define number_of_tasks_running_avl2_h

#include <stdio.h>
#include <stdlib.h>

/*
 Example:
 
 INPUT  int start[] = {0, 2, 5};
 INPUT  int end[] = {4, 8, 7};
 INPUT  int n = 3;
 INPUT  int query[] = {1, 9, 4, 3};
 INPUT  int m = 4;
 
 OUTPUT int number_of_tasks_running[m]; // {1, 0, 1, 2}
 
 NumberOfTasksRunning(number_of_tasks_running,
                      start,
                      end,
                      n,
                      query,
                      m);
 
 */

void NumberOfTasksRunning2(int number_of_tasks_running[],
                           int start[],
                           int end[],
                           int n,
                           int query[],
                           int m);

#endif /* number_of_tasks_running_avl2_h */
