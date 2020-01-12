/*************************************************************************
	> File Name: quick.cpp
	> Author:jiangxiaoyu 
	> Mail:2291372880@qq.com 
	> Created Time: 2019年10月19日 星期六 05时28分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) return ;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) --y;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) ++x;
        if (x < y) num[y--] = num[x];
    } 
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, r, x + 1);
    return ;
}

void quick_sort(int *num, int l, int r) {
    if (r <= l) return;
    int x = l, y = r, z = num[l];
    while (x < y) {
        while (x < y && num[y] >= z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] <= z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort(num, l, x - 1);
    quick_sort(num, x + 1, r);
    return ;
}

struct TreeNode {
    int root;
    int *left, *right;
};

int mindeep(struct TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
        return 1;
    } 
    int minl = 99999, min = 99999;
    if (root->left) minl = mindeep(root->left);
    if (root->right) minr = mindeep(root->right);
    return minr < minl ? (minl + 1) : (minr + 1);
}

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = temp;\
}

typedef struct {
    int *data;
    int size, cnt;
} KthLargest;

void downt(int *data, int len, int ind) {
    while (ind << 1 <= len) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (data[temp] > data[l]) temp = l;
        if (r <= len && data[temp] > data[r]) temp = r;
        if (temp == ind) break;
        swap(data[ind], data[temp]);
        ind = temp;
    }
    return;
}

void upt(int *data, int ind) {
    while (ind >> 1) {
        if (data[ind] < data[ind >> 1]) {
            swap(data[ind], data[ind >> 1]);
            ind >>= 1;
        } else {
            break;
        }
    }
}



int KthLargestAdd (KthLargest *obj, int val) {
    if (obj->size == obj->cnt) {
        if (obj->data[1] < val) {
            obj->data[1] = val;
            downt(obj->data, obj->cnt, 1);
        }
    } else {
        obj->cnt += 1;
        obj->data[obj->cnt] = val;
        upt(obj->data, obj->cnt);
    }
    return obj->data[1];
}
KthLargest* KthLargestCreate(int k, int *nums, int numsSize) {
    KthLargest *q = (KthLargest *)malloc(sizeo(KthLargest));
    q->data = (int *)malloc(sizeof(int) * (k + 1));
    q->size = k;
    q->cnt = k - 1;
    for (int i = 1; i <= q->cnt; i++) {
        q->data[i] = nums[i - 1];
    }
    for (int i = q->cnt >> 1; i >= 1; i--) {
        downt(q->data, q->cnt, i);
    }
    for (int i = k - 1; i <= numsSize - 1; i++) {
        KthLargestAdd(q, nums[i]);
    }
    return q;
}

struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *p, *q, ret;
    ret.next = NULL:
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *p, *q, ret;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

struct ListNode *reverselist(struct ListNode *head) {
    struct ListNode *p, *q, ret;
    ret.next = NULL;
    p = head;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

int query(Node t, Node u, Node v) {
    int left = u.value;
    int right = v.value;
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }
    while (true) {
        if (t.value < left) {
            t = t.right;
        } else if (t.value > right) {
            t = t.left;
        } else {
            return t.value;
        }
    }
}

int query(Node t, Node u, Node v) {
    int left = u.value;
    int right = v.value;
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }
    while (true) {
        if (t.value < left) {
            t = t.right;
        } else if (t.value > right) {
            t = t.left;
        } else {
            return t.value;
        }
    }
}

int query(Node t, Node u, Node v) {
    int left = u.value;
    int right = v.value;
    if (left > right) {
        int temp = right;
        right = left;
        left = temp;
    }
    while (true) {
        if (t.value < left) {
            t = t.r
        }
    }
}
