/*************************************************************************
	> File Name: 1.vector.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年06月29日 星期六 21时51分15秒
 ************************************************************************/

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef struct Vector {
    //data可看成不定长的数组，是个指针
    int *data;
    int size, length;
} Vector;

//初始化返回一个存储n个数据的顺序表
Vector *init(int n) {
    //动态申请顺序表的空间
    Vector *p = (Vector *)malloc(sizeof(Vector));
    //为不定长数组申请大小为sizeof(int)×n的空间,指向n个整形空间
    p->data = (int *)malloc(sizeof(int) * n);
    p->size = n;//总位数
    p->length = 0;//当前长度
    return p;
}
//返回值：是否插入成功。参数：向顺序表v中ind位置插入值为val的元素
int insert(Vector *v, int ind, int val) {
    //结构操作的头部先判断非法情况
    //顺序表满了，插入不成功
    if (v->length == v->size) return 0;
    //插入下标不合法
    if (ind < 0 || ind->length) return 0;
    //实现插入操作；
    for (int i = v->length - 1; i >= ind; i--) {
        v->data[i + 1] = v->data[i];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vector *v, int ind) {
    //删除下标不合法,ind从0开始
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v-data[i];
    }
    v->length -= 1;
    return 1;
}

//销毁操作
void clear(Vector *v) {
    //传入顺序表的地址
    if (v == NULL) return ;
    //先销毁v内部连续的存储空间
    free(v->data);
    //再销毁v内部本身占用的存储空间
    free(v);
    return ;
}

void output(Vector *v) {
    printf("arr = [");
    for (int i = 0; i < v->length; i++) {
        printf(" %d", v->data[i]);
    }
    printf("]\n");
    return ;
}


int main() {
    #define MAX_OP 20
    int op, ind, val;

    //初始化一个20位长的顺序表
    Vector *v = init(MAX_OP);
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 2;
        //保持一定概率生成一个非法值, v->length + 1为正常;
        ind = rand() % (v->length + 1);
        val = rand() % 100;
        switch(op) {
            //插入
            case 0: {
                printf("insert %d to Vector at %d = %d\n", val, ind, insert(v, ind, val));
                //打印顺序表
                output(v);
            } break;
            //删除
            case 1: {
                printf("erase element at %d from vector = %d\n", ind, erase(v, ind));
                output(v);
            } break;
            default:
            //向标准错误中输出一行代码
                fprintf(stderr, "wrong op %d\n", op);
            break;

        }
    }
    clear(v);
    return 0;
}


