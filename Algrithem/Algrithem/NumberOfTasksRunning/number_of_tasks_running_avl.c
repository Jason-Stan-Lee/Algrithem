//
//  number_of_tasks_running_avl.c
//  Algrithem
//
//  Created by JasonLee on 2017/8/3.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#include "number_of_tasks_running_avl.h"

typedef struct AvlNode *AvlTree;
typedef struct AvlNode *TimeNode;

struct AvlNode {
    
    int number_of_task_running;
    int time;
    
    AvlTree left;
    AvlTree right;
    
    int height;
};



/**
 获取当前时间点同时进行的任务数
 
 @param time 时间点
 @param tree Avl树
 @return 该时间点同时进行的任务数
 */
int FindNumberOfTasksRunning(int time, AvlTree tree);



/**
 将start时间、end时间组装成为时间节点数组
 
 @param start 任务start时间数组
 @param end 任务end时间数组
 @param n 任务数量
 @return 时间节点数组
 */
AvlTree AssembleTimeNodes(int start[], int end[], int n);



//--- Insert time_node to AvlTree ---

AvlTree Insert(TimeNode time_node, AvlTree tree);



// 分层遍历

void PrintTree(TimeNode time_node, int total);

static int Max(int a, int b);

//--- Get height of p ---

static int Height(AvlTree p);

//--- Four AVL tree Rotation ---

static AvlTree SingleRotateWithLeft(AvlTree p);
static AvlTree SingleRotateWithRight(AvlTree p);
static AvlTree DoubleRotateWithLeft(AvlTree p);
static AvlTree DoubleRotateWithRight(AvlTree p);


void NumberOfTasksRunning(int number_of_tasks_running[],
                          int start[],
                          int end[],
                          int n,
                          int query[],
                          int m)
{
    //--- 组成数组 ---
    TimeNode timeNodes = AssembleTimeNodes(start, end, n);
    
    
    //--------------------- printf --------------------------
    for (int i = 0; i < 2 * n; i++) {
        
        printf("timesArray: time: %d, num: %d point: %p\n", timeNodes[i].time, timeNodes[i].number_of_task_running, timeNodes + i);
    }
    //-------------------------------------------------------
    
    
    AvlTree tree = NULL;
    
    //--- 逐个插入 ---
    for (int i = 0; i < 2 * n; i++) {
        
        tree = Insert(timeNodes + i, tree);
    }
    
    free(timeNodes);
    
    //--- 遍历树,方便查看层级结构 ---
    PrintTree(tree, 2 * n);
    
    for (int i = 0; i < m; i++) {
        
        //--- 查找对应节点的数据 ---
        int time = query[i];
        int num = FindNumberOfTasksRunning(time, tree);
        
        number_of_tasks_running[i] = num;
        
        printf("result: time : %d, num : %d \n", time, num);
    }
}


static int Max(int a, int b)
{
    return a > b ? a : b;
}

static int Height(AvlTree p)
{
    if (p == NULL)
        
        return -1;
    else {
        
        return p->height;
    }
}

#pragma mark --

TimeNode AssembleTimeNodes(int start[], int end[], int n)
{
    //--- n的数值比较小，此处复杂度为O(n^2) ---
    
    TimeNode timeNodes = malloc(2 * n * sizeof(TimeNode));
    
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
    
    return timeNodes;
}

int FindNumberOfTasksRunning(int time, AvlTree tree)
{
    if (tree == NULL) return 0;
    
    if (time < tree->time) {
        
        // 如果应该在左子叶查找, 超出最左子叶范围, 返回0
        if (tree->left == NULL) return 0;
        
        if (time >= tree->left->time) {
            // 其时间比其左子叶晚
            
            if (tree->left->right)
                // 其左子叶包含右子叶
                
                return FindNumberOfTasksRunning(time, tree->left);
            
            else
                return tree->left->number_of_task_running;
            
        } else {
            
            return FindNumberOfTasksRunning(time, tree->left);
        }
    } else if (time > tree->time) {
        
        
        // 如果应该在右子叶查找，超出最右子叶范围返回0
        if (tree -> right == NULL) return 0;
        
        if (time < tree->right->time) {
            
            if (tree->right->left)
                // 其右子叶包含左子叶
                
                return FindNumberOfTasksRunning(time, tree->right);
            else
                
                return tree->number_of_task_running;
            
        } else {
            
            return FindNumberOfTasksRunning(time, tree->right);
        }
        
    } else {
        
        return tree->number_of_task_running;
    }
}

AvlTree Insert(TimeNode time_node, AvlTree tree)
{
    if (tree == NULL) {
        
        tree = malloc(sizeof(AvlTree));
        
        tree->number_of_task_running = time_node->number_of_task_running;
        tree->time = time_node->time;
        tree->height = 0;
        tree->left = tree->right = NULL;
        
    } else if (time_node->time < tree->time) {
        
        tree->left = Insert(time_node, tree->left);
        
        if (Height(tree->left) - Height(tree->right) == 2) {
            
            if (time_node->time < tree->left->time)
                
                tree = SingleRotateWithLeft(tree);
            else
                
                tree = DoubleRotateWithLeft(tree);
        }
    } else if (time_node->time > tree->time) {
        
        tree->right = Insert(time_node, tree->right);
        
        if (Height(tree->right) - Height(tree->left) == 2) {
            
            if (time_node->time > tree->right->time)
                
                tree = SingleRotateWithRight(tree);
            else
                
                tree = DoubleRotateWithRight(tree);
        }
        
    } else {
        //------------ The same time, do nothing -------------
        
    }
    
    tree->height = Max(Height(tree->left), Height(tree->right)) + 1;
    
    return tree;
}

#pragma mark - Four avl tree rotation

static AvlTree SingleRotateWithLeft(AvlTree p)
{
    AvlTree root;
    
    root = p->left;
    p->left = root->right;
    root->right = p;
    
    p->height = Max(Height(p->left), Height(p->right)) + 1;
    root->height = Max(Height(root->left), p->height) + 1;
    
    return root;
}

static AvlTree SingleRotateWithRight(AvlTree p)
{
    AvlTree root;
    
    root = p->right;
    p->right = root->left;
    root->left = p;
    
    p->height = Max(Height(p->left), Height(p->right)) + 1;
    root->height = Max(Height(root->right), p->height) + 1;
    
    return root;
}

static AvlTree DoubleRotateWithLeft(AvlTree p)
{
    p->left = SingleRotateWithRight(p->left);
    
    return SingleRotateWithLeft(p);
}

static AvlTree DoubleRotateWithRight(AvlTree p)
{
    p->right = SingleRotateWithLeft(p->right);
    
    return SingleRotateWithRight(p);
}

#pragma mark-- Debug

void PrintTree(TimeNode time_node, int total)
{
    
    printf("\n---------------------------------------------------\n");
    
    if (NULL == time_node) return;
    
    TimeNode *vec = (TimeNode *)malloc(total * sizeof(TimeNode));
    
    int cur = 0;
    int last = 0;
    int size = 0;
    
    vec[size++] = time_node;
    
    while (cur < size) {
        
        last = size;
        
        while (cur < last) {
            
            printf("(t: %d,n : %d)", vec[cur]->time, vec[cur]->number_of_task_running);
            
            if (vec[cur]->left) printf("L,");
            
            if (vec[cur]->right) printf("R.");
            
            
            if (NULL != vec[cur]->left) {
                
                vec[size++] = vec[cur]->left;
            }
            
            if (NULL != vec[cur]->right) {
                
                vec[size++] = vec[cur]->right;
            }
            
            cur++;
        }
        printf("\n");
    }
    
    printf("---------------------------------------------------\n\n");
    
    free(vec);
}

