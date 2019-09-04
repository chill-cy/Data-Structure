/*************************************************************************
	> File Name: 1.vector-11.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月04日 星期三 12时31分29秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector {
    int *data;
    int size, length;
} Vector;

Vector *init(int n) {
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

void clear(Vector *vec) {
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}

int expand(Vector *vec) {
    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL) return 0;
    vec->data = p;
    vec->size = new_size;
    return 1;
}

int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (ind < 0 || ind > vec->length) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("Vector expand size %d success\n", vec->size);
    }
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
    for (int i = ind + 1; i < vec->length; i++) {
        vec->data[i - 1] = vec->data[i];
    }
    vec->length -= 1;
    return 1;
}

void output(Vector *vec) {
    printf("Vector (%d) = [", vec->length);
    for(int i = 0; i < vec->length; i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    #define MAX_OP 20
    srand(time(0));
    Vector *vec = init(1);
    for (int i = 0; i < MAX_OP; i++) {
        int val, op, ind;
        val = rand() % 100;
        op = rand() % 3;
        ind = rand() % (vec->length + 1);
        switch(op) {
            case 0: 
            case 1: {
                printf("insert %d at %d to Vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 2: {
                printf("erase item at %d from Vector = %d\n", ind, erase(vec, ind));
            } break;
        }
        output(vec);
        printf("\n");
    }
    clear(vec);
    return 0;
}
