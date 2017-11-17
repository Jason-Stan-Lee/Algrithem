//
//  add_two_numbers.c
//  Algrithem
//
//  Created by Jason on 2017/11/16.
//  Copyright © 2017年 tdrhedu. All rights reserved.
//

#include "add_two_numbers.h"
struct ListNode* creatListNode(int val);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode* p = &head;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        struct ListNode* node = creatListNode(sum % 10);
        p->next = node;
        p = p->next;
        
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    
    return head.next;
}

struct ListNode* creatListNode(int val) {
    
    struct ListNode* node;
    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = val;
    
    return node;
}
