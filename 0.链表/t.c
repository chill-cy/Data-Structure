/*************************************************************************
	> File Name: t.c
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年07月08日 星期一 16时51分35秒
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct Vector {//结构定义
    int *data;//连续的存储区
    int size, length;
} Vector;

#define default_value(n, val) ((#n)[0] ? n + 0 : val)
#define init(n) __init(default_value(n, 10))

Vector *__init(int n) {//初始化一个存储n个元素的顺序表
    Vector *vec = (Vector *)malloc(sizeof(Vector));//先申请顺序表的存储空间
    vec->data = (int *)malloc(sizeof(int) * n);//申请顺序表中连续存储区的数据空间
    vec->size = n;//初始化size
    vec->length = 0;
    return vec;
}

int expand(Vector *vec) {
    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;//顺序表为空
    free(vec->data);//先销毁数据区
    free(vec);//再销毁顺序表本身的空间
    return ;
}

int insert(Vector *vec, int ind, int val) {//返回值本次插入是否成功，参数：向vec顺序表ind中插入值为val的元素
    if (vec == NULL) return 0;//不能向空顺序表中插入
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector size to %d success\n", vec->size);
    }//顺序表满了
    if (ind < 0 || ind > vec->length) return 0;//插入位置非法，最后一个元素的位置length - 1;可以插入最后一个元素的后一位为length
    for (int i = vec->length; i > ind; i--) {
        vec->data[i] = vec->data[i - 1];                                           
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(Vector *vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind; i < vec->length - 1; i++) {
        vec->data[i] = vec->data[i + 1];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    printf("Arr[%d] = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));//传入当前时间作为随机种子
    #define MAX_OP 20
    Vector *vec = init();
    int op, ind, val;
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 4;//随机数
        ind = rand() % (vec->length + 1);//vec->length初始化为０,%0操作非法
        val = rand() % 100;
        switch(op) {
            case 2: 
            case 3: 
            case 0: {//插入
                printf("insert %d at %d to Vector\n", val, ind);
                insert(vec, ind, val);
            } break;
            case 1: {
                printf("erase item at %d from vector\n", ind);
                erase(vec, ind);
            } break;
        }
        output(vec);
    } 
    return 0;
}
