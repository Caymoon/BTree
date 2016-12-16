/**
 * Created by gblau on 2016-12-04.
 * Copyright (c) Chung Tsing(gblau) 2016. All rights reserved.
 */

#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H

#include "linklist.h"
#define BTREELENGTH 50
#define BTLEN (sizeof(Node))

#endif //B_TREE_BTREE_H


/**
 * 树的初始化
 * @param treePtr
 */
void initBTree(BTree *treePtr);

/**
 * 判断一个节点是否有数据
 */
bool isEmpty(const BTree tree);

/**
 * 判断一个节点的数据是否已满
 */
bool isFull(const BTree tree);

/**
 * 获取一个节点的阶数
 * @param tree
 * @return 阶数
 */
int getKeyNumber(const BTree tree);

/**
 * 寻找逼树最大节点
 * @param tree
 * @return
 */
BTree findMax(const BTree tree);

/**
 * 寻找逼树最大节点的keyNum
 * @param tree
 * @return
 */
int findMaxNum(BTree tree);

/**
 * 最小节点
 * @param tree
 * @return
 */
BTree findMin(BTree tree);

/**
 * 插入一阶数据
 * @param tree
 * @param key
 * @param q
 * @param i
 */
bool insertBTree(BTree *tree, Record record);

/**
 * 搜索指定数据
 * @param tree
 * @param key 指定数据key
 * @return
 */
ResultVo searchNode(const BTree tree, int key);

/**
 *
 * @param tree
 * @param i
 */
bool deleteNode(BTree *tree, int i);