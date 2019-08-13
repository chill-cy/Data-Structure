/*************************************************************************
	> File Name: link_reverse.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年08月13日 星期二 14时57分35秒
 ************************************************************************/

#include <iostream>
#include<iostream>
using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int insert(Node *head, int ind, int value) {
    if (head == NULL) return 0;
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = value;
    q->next = NULL;
    Node *tmp = head->next;
    head->next = q;
    q->next = tmp;
    return 1;
}

int output(Node *head) {
    if (head == NULL) return 0;
    Node *q = head->next;
    while (q) {
        printf("%d\n", q->data);
        q = q->next;
    }
    return 1;
}

int _delete(Node *head, int ind) {
    if (head == NULL) return 0;
    Node *q = head;
    ind--;
    while (ind) {
        q = q->next;
        ind--;
    }
    Node *tmp = q->next;
    q->next = q->next->next;
    free(tmp);
    return 1;
}

int reverse(Node *head) {
    if (head->next == NULL) return 0;
    Node *q = head->next;
    Node *tmp = NULL;
    while (q != NULL) {
        q->next = head->next;
        head->next = q;
        q->next->next = tmp;
        q = tmp;
        tmp = tmp->next;
    }
    return 1;
}

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    int m, t;
    int a, b, k;
    cin >> m >> t;
    while (m--) {
        if (t == 1) {
            cin >> a >> b;
            k = insert(head, a, b);
            if (k == 1) cout << "success" << endl;
            else cout << "failed" << endl;
        }
        if (t == 2) {
            output(head);
        }
        int ind;
        if (t == 3) {
            cin >> ind;
            int k = _delete(head, ind);
            if (k == 1) cout << "success" << endl;
            else cout << "failed" << endl;
        }
        if (t == 4) {
            int k = reverse(head);
            if (k == 1) cout << "success" << endl;
            else cout << "failed" << endl;
        }
    }
    return 0;
}
