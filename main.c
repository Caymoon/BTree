#include <stdio.h>
#include <time.h>
#include "btree.h"

static void test();

static void putMessages();

int main() {
    putMessages();
    test();
    return 0;
}

static void test() {
    int treeLength;
    int keyArray[BTREELENGTH];
    BTree tree = NULL;
    Record record;
    srand((unsigned) time(NULL));
    treeLength = rand() % BTREELENGTH;
    //自己输入数据
    //scanf("%d", &n);
    printf("B树的阶为:%d,插入次数为:%d\n", M, treeLength);
    for (int i = 0; i < treeLength; i++) {
        record.key = rand() % MAXINT;
        //自己输入
        //scanf("%d", &d.key);
        keyArray[i] = record.key;
        if (insertBTree(&tree, record))
            printf("\n第%d次插入%d:\n", i + 1, record.key);
        else
            printf("\n第%d次插入%d不成功:\n", i + 1, record.key);
        printTree(tree);
    }

    puts("\n请输入查找的元素，如果退出则按任意非数字吧");
    while(scanf("%d", &record.key)) {
        ResultVo result = searchNode(tree, record.key);
        if(result.tag) {
            printf("这是节点的第%d个元素\n", result.i);
        } else {
            printf("没有该节点。\n");

        }
        puts("请继续输入查找的元素，如果退出则按任意非数字吧");
    }

    for (int i = 0; i < treeLength; i++) {
        record.key = keyArray[i];
        if (deleteNode(&tree, record.key))
            printf("\n第%d次删除%d:\n", i + 1, record.key);
        else
            printf("\n第%d次删除%d不成功:\n", i + 1, record.key);
        printTree(tree);
    }
}

static void putMessages() {
    puts("---------------------------------------------------");
    puts("| 班级:15计科(3)班    学号:3115004974    姓名:刘国斌 |");
    puts("---------------------------------------------------\n");

    puts(" *************************************************************************************************************");
    puts(" * 阶数 : 4");
    puts(" *************************************************************************************************************\n");

    puts("---------------------------------------------------");
}