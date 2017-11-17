//
//  add_two_numbers.h
//  Algrithem
//
//  Created by Jason on 2017/11/16.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#ifndef add_two_numbers_h
#define add_two_numbers_h

#include <stdio.h>
#include <stdlib.h>
/*
 LeetCode 2
 
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif /* add_two_numbers_h */
