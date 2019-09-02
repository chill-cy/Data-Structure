/*************************************************************************
	> File Name: 14.hash_table-1.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月15日 星期四 11时24分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char *str;
    struct Node *next;
} Node;


typedef struct HashTable {
    //存储若干链表头地址的数组
    Node **data;
    int size;
} HashTable;

//头插法
Node *init_node(char *str, Node *head) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->str = strdup(str);
    p->next = head;
    return p;
}

HashTable *init_hashtable(int n) {
    HashTable *h = (HashTable *)malloc(sizeof(HashTable));
    h->size = n << 1;
    //存储若干链表头地址的数组的每一位的地址应该使用calloc初始化为空
    h->data = (Node **)calloc(sizeof(Node *), h->size);
    return h;
}

void clear_node(Node *node) {
    if (node == NULL) return ;
    Node *p = node, *q;
    while (p) {
        q = p->next;
        free(p->str);;
        free(p);
        p = q;
    }
    return ;
}

void clear_hashtable(HashTable *h) {
    if (h == NULL) return ;
    for (int i = 0; i < h->size; i++) clear_node (h->data[i]);
    free(h->data);
    free(h);
    return ;
}

int BKDRHash(char *str) {
    //设置种子
    int seed = 31, hash = 0;
    for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
    //返回正值
    return hash & 0x7fffffff;
}

int insert (HashTable *h, char *str) {
    //获得hash值
    int hash = BKDRHash(str);
    //将hash转化为数组下标
    int ind = hash % h->size;
    h->data[ind] = init_node(str, h->data[ind]);
    /*二次试探法
     * int times = 0;
     * Node *node = init_node(str, NULL);
     * while (h->data[ind]) {
     * times++;
     * ind += times * times;
     * ind %= h->size;
    * }
    * h->data[ind] = node*/
    return 1;
}

int search(HashTable *h, char *str) {
    int hash = BKDRHash(str);
    int ind = hash % h->size;
    Node *p = h->data[ind];
    while(p && strcmp(p->str, str)) p = p->next;
    return p != NULL;
}

int main() {
    int op;
    char str[100];
    HashTable *h = init_hashtable(100);
    while(scanf("%s%s", &op, str) != EOF) {
        switch(op) {
            case 0: {
                printf("insert %s to hash table\n", str);
                insert(h, str);
            } break;
            case 1: {
                printf("search %s result = %d\n", str, search(h, str));
            } break;
        }
    }
    return 0;
}
