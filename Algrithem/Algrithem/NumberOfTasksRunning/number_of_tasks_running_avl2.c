//
//  number_of_tasks_running_avl2.c
//  Algrithem
//
//  Created by JasonLee on 2017/8/3.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//


#include "number_of_tasks_running_avl2.h"

typedef struct TimeNode {
    
    int time;
    int number_of_task_running;
    
    struct TimeNode *left;
    struct TimeNode *right;
    int height;
    
} TimeNode, *AvlTree;

//--- 计算时长
void Assemble(TimeNode *timeNodes, int start[], int end[], int n)
{
    for (int i = 0; i < 2 * n; i++) {
        
        int time = i < n ? start[i] : end[i - n];
        int num_tasks_running = 0;
        
        for (int j = 0; j < n; j++) {
            
            if (time >= start[j] && time < end[j])
                ++num_tasks_running;
        }
        timeNodes[i].number_of_task_running = num_tasks_running;
        timeNodes[i].time = time;
    }
}

// 快速排序
void Quiksort(TimeNode* time_nodes,int low,int high)
{
    int i = low;
    int j = high;
    int time = time_nodes[i].time;
    int num_tasks_running = time_nodes[i].number_of_task_running;
    
    if( low < high) {
        
        while(i < j) {
            
            while((time_nodes[j].time >= time) && (i < j)) {
                
                j--;
            }
            
            time_nodes[i].time = time_nodes[j].time;
            time_nodes[i].number_of_task_running = time_nodes[j].number_of_task_running;
            
            while((time_nodes[i].time <= time) && (i < j)) {
                
                i++;
            }
            
            time_nodes[j].time= time_nodes[i].time;
            time_nodes[i].number_of_task_running = time_nodes[j].number_of_task_running;
            
        }
        
        time_nodes[i].time = time;
        time_nodes[i].number_of_task_running = num_tasks_running;
        
        Quiksort(time_nodes,low,i-1);
        Quiksort(time_nodes,j+1,high);
    } else {
        
        return;
    }
}

// 有序数组转化为平衡树
AvlTree SortedArrayToAvlTree(TimeNode *time_nodes, int start, int end)
{
    if (start > end) return NULL;
    
    int mid = start + (end - start) / 2;
    
    TimeNode * node = time_nodes + mid;
    
    node->left = SortedArrayToAvlTree(time_nodes, start, mid - 1);
    node->right = SortedArrayToAvlTree(time_nodes, mid + 1, end);
    
    return node;
}

int FindNumberOfTasksRunning2(int time, AvlTree tree)
{
    if (time < tree->time) {
        
        return FindNumberOfTasksRunning2(time, tree->left);
    } else if (tree->right != NULL && time > tree->right->time) {
        
        return FindNumberOfTasksRunning2(time, tree->right);
    } else {
        
        return tree->number_of_task_running;
    }
}

void NumberOfTasksRunning2(int number_of_tasks_running[],
                           int start[],
                           int end[],
                           int n,
                           int query[],
                           int m)
{
    TimeNode *timeNodes = (TimeNode *)malloc(2 * n * sizeof(TimeNode));
    Assemble(timeNodes, start, end, n);
    
    Quiksort(timeNodes, 0, 2 * n - 1);
    
    AvlTree tree = SortedArrayToAvlTree(timeNodes, 0, 2 * n - 1);
    
    for (int i = 0; i < m; i++) {
        
        number_of_tasks_running[i] = FindNumberOfTasksRunning2(query[i], tree);
    }
    
    for (int i = 0; i < m; i++) {
        
        printf("%d%c", number_of_tasks_running[i], i < m - 1 ? ',' : '\n');
    }

    
    free(timeNodes);
}

