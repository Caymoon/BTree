/*
 * Created by gblau on 2016-12-04.
 * Copyright (c) Chung Tsing(gblau) 2016. All rights reserved.
 */
#include <stdio.h>
#include "btree.h"

/**
 * 初始化树
 * @param tree
 */
void initBTree(BTree tree) {
    tree->parent = NULL;
    tree->keyNum = 0;
    for (int i = 0; i < MAX_STAIRS+1; ++i) {
        tree->childArray[i] = NULL;
    }
    for (int j = 0; j < MAX_STAIRS+1; ++j) {
        tree->keyArray[j] = 0;
    }
}

/**
 * 判断该节点数据是否为空
 * @param tree
 */
bool isEmpty(const BTree tree) {
    return 0 == tree->keyNum ? true : false;
}

/**
 * 判断该节点数据是否已满
 * @param tree
 */
bool isFull(const BTree tree) {
    return MAX_STAIRS == tree->keyNum ? true : false;
}

/**
 * 获取该节点的key数
 * @param tree
 */
int getKeyNumber(const BTree tree) {
    return tree->keyNum;
}

/**
 * 插入一个节点
 * @param tree
 * @param k
 * @param q
 * @param i
 */
void insertNode(BTree *tree, int key, BTree q, int i) {

}

/**
 * 搜索：是否存在指定数据
 * @param tree
 * @param k 指定数据key
 * @return
 */
ResultVo searchNode(const BTree tree, int key) {
    int i = 0;
    int found = 0;
    BTree p = tree;
    BTree q = NULL;
    ResultVo result;

    while(p && 0==found) {
        i = searchKeyRange(p, key);

        if(i <= p->keyNum && p->keyArray[i] == key)
            found = 1;
        else {
            q = p;
            p = p->childArray[i-1];
        }
    }

    if(found) {
        result.pt = p;
        result.i = i;
        result.tag = 1;
    } else {
        result.pt = q;
        result.i = i;
        result.tag = 0;
    }

    return result;
}

/**
 * 查找指定key或者缩小key的范围。
 * @param p
 * @param k 要查找的key
 * @return
 */
static int searchKeyRange(BTree p, int key) {
    int i = 1;
    while(i <= p->keyNum && key > p->keyArray[i])
        ++i;
    return i;
}

/**
 * 删除一个节点
 * @param tree
 * @param i
 */
void deleteNode(BTree tree, int i) {

}

