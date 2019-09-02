/*************************************************************************
	> File Name: 1.vector-4.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月01日 星期日 13时55分01秒
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
    vec->length = 0;
    vec->size = n;
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


int insert(Vector *vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector size to %d success\n", vec->size);
    }
    if (ind < 0 || ind > vec->length) return 0;
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
    printf("Vector(%d) = [", vec->length);
    for (int i = 0; i < vec->length; i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return ;
}

void clear(Vector *vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Vector *vec = init(1);
    int op, ind, val;
    for (int i = 0;  i < MAX_OP; i++) {
        op = rand() % 4;
        val = rand() % 100;
        ind = rand() % (vec->length + 3);
        switch(op) {
            case 3:
            case 2:
            case 0: {
                printf("insert %d at %d to vector = %d\n", val, ind, insert(vec, ind, val));
            } break;
            case 1: {
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
            } break;
        }
        output(vec);
    }
    clear(vec);
    return 0;
}
