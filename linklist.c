/**
 * Created by gblau on 2016-12-11.
 * Copyright (c) Chung Tsing(gblau) 2016. All rights reserved.
 */
#include "linklist.h"
#include <stdio.h>

static LinkList buildNode(BTree tree);

static bool ergodic(BTree tree, LinkList list, int newline, int sum);

/**
 * 初始化队列
 */
bool initQueue(LinkList *list) {
    NULL == ((*list) = (LNode *) malloc(sizeof(LNode))) ? false : ((*list)->next = NULL), true;
}

/**
 * 插入队列结点
 * @param node 队列尾部
 * @Param tree 新节点的数据
 */
bool insertQueueNode(LNode *node, BTree tree) {
    if (NULL == node) return false; // 参数不合理
    while (node->next != NULL)
        node = node->next;
    node->next = buildNode(tree);         // 对应图4.11（b）的②，修改p结点的指针域
    return true;
}

/**
 * 构造结点
 * @Param tree 新节点
 */
static LinkList buildNode(BTree tree) {
    LNode *p;
    p = (LNode *) malloc(sizeof(LNode)); // 分配结点空间
    if (p != NULL) {
        p->data = tree;
        p->next = NULL;
    }
    return p;
}

/**
 * 删除队列结点
 * @param node 队列尾部
 * @Param tree B树
 */
bool deleteQueueNode(LNode *node, BTree *tree) {
    LNode *q;
    if (NULL == node || NULL == node->next)
        return false; // 删除位置不合理
    q = node->next;
    node->next = q->next; // 修改被删结点q的指针域
    (*tree) = q->data;
    free(q); // 释放结点q
    return true;
}

/**
 * 销毁整个队列
 * @Param list 队列指针
 */
bool destroyQueue(LinkList list) {
    LinkList p;
    if (list != NULL) {
        p = list;
        list = list->next;
        free(p);
        destroyQueue(list);
    }
}

/**
 * 判空
 * @Param list 队列指针
 */
bool ifEmpty(LinkList list) {
    return list != NULL && list->next == NULL ? true : false;
}

bool printTree(BTree tree) {
    LinkList L;
    if (tree == NULL) {
        printf("[ ]\n");
        return true;
    }
    initQueue(&L);
    ergodic(tree, L, 0, 0);
    destroyQueue(L);
    return true;
}

/**
 * 层次遍历的算法实现
 * @param tree 二叉树
 * @param list 队列
 * @param newline 行
 * @param sum 节点总数，初始为0
 * @return
 */
static bool ergodic(BTree tree, LinkList list, int newline, int sum) {
    int index;
    BTree p;
    if (tree != NULL) {
        printf("[ ");
        insertQueueNode(list, tree->child[0]);
        for (index = 1; index <= tree->keyNum; index++) {
            printf("%d ", tree->keys[index]);
            insertQueueNode(list, tree->child[index]);
        }
        sum += tree->keyNum + 1;
        printf("]");
        if (newline == 0) {
            printf("\n");
            newline = sum - 1;
            sum = 0;
        } else {
            --newline;
        }
    }
    if (!ifEmpty(list)) {
        deleteQueueNode(list, &p);
        ergodic(p, list, newline, sum);
    }
    return true;
}