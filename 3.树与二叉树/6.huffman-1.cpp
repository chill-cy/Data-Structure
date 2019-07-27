/*************************************************************************
	> File Name: huffman.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月23日 星期二 23时58分41秒
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_N 1000
//__typeof定义中间变量的类型应该和a的类型相同
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b, b = temp; \
}
using namespace std;

typedef struct Node {
    char ch;//当前结点所对应的字符
    double p;//当前结点所对应的概率值
    struct Node *next[2];
} Node;

//记录相关字符，以及它的编码
typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct HaffmanTree {//哈弗曼树的树形结构
    Node *root;
    //记录多少种字符
    int n;
    //记录n种字符的编码
    Code *codes;
} HaffmanTree;

typedef struct Data {
    char ch;//字符
    double p;//频次
} Data;

Data arr[MAX_N + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

int extractCodes(Node *root, Code *arr, int k, int l, char *buff) {
    //当前结点为叶子节点时才代表一个独立的结点
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        //在当前结点之前已经提取了k个字符的编码
        //当前结点的编码应该放到k个位置，假设编码已经提取到了
        arr[k].ch = root->ch;
        //将内容完整的复制一份,有malloc的部分
        arr[k].str = strdup(buff);
        //当前编码了一个字符
        return 1;
    } 
    //当前所在结点不是一个叶子结点，就需要向左和右子树分别进行编码的提取，
    //delta = 0;在相关子树中编码了多少个字符
    int delta = 0;
    buff[l] = '0';//向左子树中走
    delta += extractCodes(root->next[0], arr, k , l + 1, buff);
    buff[l] = '1';
    delta += extractCodes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

HaffmanTree *getNewTree(int n) {
    HaffmanTree *tree = (HaffmanTree *)malloc(sizeof(HaffmanTree));
    //初始化n个编码的信息
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->root = NULL;
    tree->n = n;
    return tree;
}

void insertOnce(Node **arr, int n) {//n插入排序最后一位的位置
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
    return ;
}

HaffmanTree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);//要开辟的是存储结点地址的数组所以使用**;存储哈弗曼结点地址的数组,将每一个字符变成哈弗曼树中的一个结点，一会儿再将每俩个结点进行合并
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);//传入地址
    }
    //进行n - 1轮合并，先将所有字符出现的频次先从大到小排序
    for (int i = 1; i < n; i++) {//插入排序，将第i位向前插入直到前面没有比它小的元素，
        insertOnce(nodes, i);
    }
    //n-1轮合并
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i];
        p->next[1] = nodes[i - 1];
        //新生成结点的概率等于两个结点概率相加之和
        p->p = p->next[0]->p + p->next[1]->p;
        //将新结点放到第i - 1位  
        nodes[i - 1] = p;
        //将当前结点向前进行插入排序
        insertOnce(nodes, i - 1);
    }
    //获得一颗新的树,维护n种字符
    HaffmanTree *tree = getNewTree(n);
    //所生成的根结点在nodes数组的第一位
    tree->root = nodes[0];
    free(nodes);
    //如何提取出n个字符的编码//当前所在的哈弗曼树的根结点，参数２将提取出来的编码放到哪个位置数组中，参数３当前提取得到的是第几个编码，先从第０个字符的编码开始提取，参数４记录路径长度，初始为０，最后一位buff表示已经提取到的字符的编码,buff最长也就是n位的编码
    char *buff = (char *)malloc(sizeof(char) * n);
    extractCodes(tree->root, tree->codes, 0, 0, buff);
    free(buff);
    return tree;
}

int main() {
    int n;
    char str[10];//一位字符，开个数组可以省去判断是否需要吞掉空格和换行
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {//读入数据
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    HaffmanTree *tree = build(arr, n);//建立一个哈弗曼树，将所有数据以及n传入表示建立n个字符的哈弗曼树
    //输出每一个字符的编码
    for (int i = 0; i < tree->n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
