/**
 * Created by gblau on 2016-12-04.
 * Copyright (c) Chung Tsing(gblau) 2016. All rights reserved.
 */
#include <stdbool.h>

#ifndef B_TREE_BTREE_H
#define B_TREE_BTREE_H
//最大子树数
#define MAX_STAIRS 3
#endif //B_TREE_BTREE_H

//自定义key类型
typedef int Key;

/**
 * B树的基本节点
 */
typedef struct node {
    int keyNum;
    Key keyArray[MAX_STAIRS+1];
    struct node *parent;
    struct node *childArray[MAX_STAIRS+1];

}Node, *BTree;

/**
 * 封装查找返回的信息
 */
typedef struct result {
    BTree pt;
    int i;
    int tag;
}ResultVo;

/**
 * 树的初始化
 * @param tree
 */
void initBTree(BTree *tree);

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
 * 插入一阶数据
 * @param tree
 * @param key
 * @param q
 * @param i
 */
void insertNode(BTree *tree, int key, BTree q, int i);

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
void deleteNode(BTree *tree, int i);






