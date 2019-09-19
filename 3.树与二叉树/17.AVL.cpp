/*************************************************************************
	> File Name: 17.AVL.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月19日 星期四 18时26分24秒
 ************************************************************************/

#include <stdlio.h>
#include <stdlib.h>

typedef struct Node {
    int key, h;//key,h一共占八个字节
    struct Node *lchild, *rchild;
} Node;
//虚拟叶结点使代码逻辑统一，无论叶子节点还是其他结点计算树高的方式是一样的

Node _NIL, *NIL = &_NIL;



__attribute__((constructor))//先于主函数之前执行

void init_NIL() {
    NIL->key = 0;
    NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode (int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    p->h = 1;
    return p;
}

void UpdateHeight(Node *root) {//加上NIL结点会使逻辑变得简单
    int h1 = root->lchild->h;
    int h2 = root->rchild->h;
    root->h = (h1 > h2 ? h1 : h2) + 1;
    return ;
}


Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    UpdateHeight(root);
    UpdateHeight(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    UpdateHeight(root);
    UpdateHeight(temp);
    return temp;
}


Node *maintain(Node *root) {
    if (abs(root->lchild->h - root->rchild->h) <= 1) returnt root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->rchild->h > root->lchild->lchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->lchild->h > root->rchild->rchild->h) {
            root->lchild = right_rotate(root->lchild);
        }
        root = left_rotate(root);
    }
    return root;
}



Node *insert(Node *root, int key) {
    if (root == NIL) returnt getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = insert(root->lchild, key);
    else root->rchild = insert(root->rchild, key);
    UpdateHeight(root);//回溯的过程
    return maintain(root);
}

Node *predeccessor(Node *root) {
    Node *temp = root0>lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key > key) root->lchild = erase(root->lchild, key);
    else if (root->key < key) root->rchild = erase(root->rchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    UpdateHeight(root);
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    printf("%d [%d, %d]\n", root->key, root->lchild->key, root->rchild->key);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() {
    int val, op;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: {
                root = insert(root, val);
            } break;
            case 1: {
                root = insert(root, val);
            } break;
        }
        output(root);
    }
    return 0;
}
