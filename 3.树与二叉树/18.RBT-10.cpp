/*************************************************************************
	> File Name: 18.RBT-10.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年09月29日 星期日 11时45分24秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

Node _NIL, *const NIL = &_NIL;
__attribute__((constructor))
void init() {
    NIL->key = 0;
    NIL->color = BLACK;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)calloc(sizeof(Node), 1);
    p->key = key;
    p->color = RED;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

int has_red_child(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root;
    if (root->rchild->color == DOUBLE_BLACK) {
        if (root->lchild->color == RED) {
            root->lchild->color == BLACK;
            root->color = RED;
            root = right_rotate(root);
            root->rchild = erase_maintain(root->rchild);
            return root;
        }
        if (!has_red_child(root->lchild)) {
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            root->color += 1;
            return root;
        }
        if (root->lchild->lchild->color != RED) {
            root->lchild->rchild->color = BLACK;
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild);
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    } else {
        if (root->rchild->color == RED) {
            root->rchild->color = BLACK;
            root->color = RED;
            root = left_rotate(root);
            root->lchild = erase_maintain(root->lchild);
            return root;
        } 
        if (!has_red_child(root->rchild)) {
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->rchild->rchild->color != RED) {
            root->rchild->lchild->color = BLACK;
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild);
        }
        root->rchild->color = root->color;
        root->lchild->color -= 1;
        root = left_rotate(root);
        root->lchild->color = root->rchild->color = BLACK;
    }
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *_erase(Node *root, int key) {
    if (root == NIL) return root;
    if (root->key < key) root->rchild = _erase(root->rchild, key);
    else if (root->key > key) root->lchild = _erase(root->lchild, key);
    else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = _erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = _erase(root, key);
    root->color = BLACK;
    return root;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == RED && root->rchild->color == RED) {
        if (!has_red_child(root->lchild) && !has_red_child(root->rchild)) return root;
        goto insert_end;
    }
    if (root->lchild->color == RED) {
        if (!has_red_child(root->lchild)) return root;
        if (root->lchild->rchild->color == RED) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (!has_red_child(root->rchild)) return root;
        if (root->rchild->lchild->color == RED) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
insert_end:
    root->color = RED;
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *_insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = _insert(root->rchild, key);
    else root->lchild = _insert(root->lchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = _insert(root, key);
    root->color = BLACK;
    return root;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d %d %d %d\n", root->key, root->color, root->lchild->key, root->rchild->key);
    output(root->rchild);
    return ;
}


int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch(op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root); break;
        }
    }
    return 0;
}
