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
    //�Լ���������
    //scanf("%d", &n);
    printf("B���Ľ�Ϊ:%d,�������Ϊ:%d\n", M, treeLength);
    for (int i = 0; i < treeLength; i++) {
        record.key = rand() % MAXINT;
        //�Լ�����
        //scanf("%d", &d.key);
        keyArray[i] = record.key;
        if (insertBTree(&tree, record))
            printf("\n��%d�β���%d:\n", i + 1, record.key);
        else
            printf("\n��%d�β���%d���ɹ�:\n", i + 1, record.key);
        printTree(tree);
    }

    puts("\n��������ҵ�Ԫ�أ�����˳�����������ְ�");
    while(scanf("%d", &record.key)) {
        ResultVo result = searchNode(tree, record.key);
        if(result.tag) {
            printf("���ǽڵ�ĵ�%d��Ԫ��\n", result.i);
        } else {
            printf("û�иýڵ㡣\n");

        }
        puts("�����������ҵ�Ԫ�أ�����˳�����������ְ�");
    }

    for (int i = 0; i < treeLength; i++) {
        record.key = keyArray[i];
        if (deleteNode(&tree, record.key))
            printf("\n��%d��ɾ��%d:\n", i + 1, record.key);
        else
            printf("\n��%d��ɾ��%d���ɹ�:\n", i + 1, record.key);
        printTree(tree);
    }
}

static void putMessages() {
    puts("---------------------------------------------------");
    puts("| �༶:15�ƿ�(3)��    ѧ��:3115004974    ����:������ |");
    puts("---------------------------------------------------\n");

    puts(" *************************************************************************************************************");
    puts(" * ���� : 4");
    puts(" *************************************************************************************************************\n");

    puts("---------------------------------------------------");
}