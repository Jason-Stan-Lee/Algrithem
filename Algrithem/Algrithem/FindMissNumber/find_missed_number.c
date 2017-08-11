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

校营通PC：
1.根据招生秀拟定的开发计划着手开发

校营通Andriod：
1.直播详情页顶部titlebar自定义样式
2.应用弹窗样式统一
3.登录验证逻辑优化
4.部分界面调整
5.应用性能优化

高效阅读iOS：
1.对目前项目的网络请求和 视幅训练逻辑等 做优化工作
2.检索分享书籍的问题，并考虑解决方案
3.对新功能模块做准备工作

高效阅读Andriod：
1.组词模块的跳转逻辑实现
2.阅读记录逻辑优化
3.阅读测试结果显示优化
4.修改视幅训练游戏逻辑
5.优化视幅训练答题
6.优化关卡
7.跟进组词资源添加进度


int *quick_sort(int array[])
{
    
    
    return array;
}

int find_missed_number_with_sorted(int array[], int n)
{
    
    return -1;
}
