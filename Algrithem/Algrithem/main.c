//
//  main.c
//  Algrithem
//
//  Created by JasonLee on 2017/8/3.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#include <stdio.h>
#include "number_of_tasks_running_avl2.h"
#include "number_of_tasks_running_avl.h"

int main(int argc, const char * argv[]) {
    
    // insert code here...
    
    int start[] = {0, 2, 5};
    int end[] = {4, 8, 7};
    int n = 3;
    int query[] = {1, 9, 4, 3};
    int m = 4;
    
    int number_of_tasks_running[m]; // {1, 0, 1, 2}
    
    /*
     
    NumberOfTasksRunning2(number_of_tasks_running,
                          start,
                          end,
                          n,
                          query,
                          m);
     
     */
    
    NumberOfTasksRunning(number_of_tasks_running,
                         start,
                         end,
                         n,
                         query,
                         m);
    
    return 0;
}
